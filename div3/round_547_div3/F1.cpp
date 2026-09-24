/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-23 17:08:46
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1500+10;
int n;
int A[N];
map<int,vector<pair<int,int>>> save;
bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) {
        int sum = A[i];
        save[sum].push_back({i,i});
        for (int j = i+1; j <= n; j++) {
            sum += A[j];
            save[sum].push_back({i, j});
        }
    }
    for (auto& it : save) {
        sort(it.second.begin(), it.second.end(), cmp);
    }
    vector<pair<int,int>> ret;
    for (auto it : save) {
        vector<pair<int,int>> store;
        pair<int,int> prev = {INT32_MIN, INT32_MIN};
        for (pair<int,int> p : it.second) {
            if (p.first > prev.second) {
                prev = p;
                store.push_back(p);
            }
        }
        if (store.size() > ret.size()) {
            ret = store;
        }
    }
    cout << ret.size() << '\n';
    for (pair<int,int> r : ret) cout << r.first << ' ' << r.second << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





