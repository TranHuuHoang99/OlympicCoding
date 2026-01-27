/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-27 20:35:04
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, m;
int A[N];
void solve(void) {
    cin >> n >> m;
    int k = n/m;
    vector<vector<int>> remain(m+1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        remain[A[i] % m].push_back(i);
    }
    int ret = 0;
    vector<pair<int,int>> save;
    for (int i = 0; i < 2*m; i++) {
        int cur = i % m;
        while (remain[cur].size() > k) {
            int idx = remain[cur].back();
            remain[cur].pop_back();
            save.push_back({idx, i});
        }
        while (remain[cur].size() < k && !save.empty()) {
            auto [idx, mmod] = save.back();
            save.pop_back();
            remain[cur].push_back(idx);
            A[idx] += i - mmod;
            ret += i - mmod;
        }
    }
    cout << ret << endl;
    for (int i = 0; i < n; i++) cout << A[i] << ' ';
    cout << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





