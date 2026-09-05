/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-06 19:20:23
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n, k;
int numb_changes = 1;
void solve(void) {
    cin >> n >> k;
    vector<pair<int,int>> ret;
    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = i+1; j <= k; j++) {
            ret.push_back({i,j});
            cnt++;
            if (cnt >= n) break;
            ret.push_back({j,i});
            cnt++;
            if (cnt >= n) break;
        }
        if (cnt >= n) break;
    }
    if (cnt != n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (pair<int,int> r : ret) {
        cout << r.first << ' ' << r.second << '\n';
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





