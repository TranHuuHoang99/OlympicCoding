/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-29 23:29:35
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

void solve(void) {
    int n, k;
    cin >> n >> k;
    string ret = "";
    for (int i = 0; i < n; i++) {
        ret += char('a'+(i%k));
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}





