/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-07 14:30:34
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

void solve(void) {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        int ret = (val * a % b) / a;
        cout << ret << ' ';
    }
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





