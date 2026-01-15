/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-12 11:35:15
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int k;
unordered_map<int,vector<pair<int,int>>> save;
vector<int> A[N];
int totalSum[N];
void solve(void) {
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int n;
        cin >> n;
        int sum = 0;
        vector<pair<int,int>> temp;
        set<int> track;
        for (int j = 1; j <= n; j++) {
            int val;
            cin >> val;
            A[i].push_back(val);
            sum += val;
            if (track.find(val) == track.end()) {
                temp.push_back({val, j});
                track.insert(val);
            }
        }
        for (pair<int,int> t : temp) {
            save[sum-t.first].push_back({i, t.second});
        }
        totalSum[i] = sum;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < A[i].size(); j++) {
            int curIdx = j+1;
            int curVal = A[i][j];
            int need = totalSum[i] - curVal;
            if (save.find(need) == save.end()) continue;
            for (pair<int,int> s : save[need]) {
                if (s.first != i) {
                    cout << "YES" << endl;
                    cout << i << ' ' << curIdx << endl;
                    cout << s.first << ' ' << s.second << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}