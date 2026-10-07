/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-07 16:38:53
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void init(void) {

}
void solve(void) {
    int k, n, a, b;
    cin >> k >> n >> a >> b;
    if (n * b >= k) {
        cout << -1 << '\n';
        return;
    }
    int x = ((k-1) - (n * b)) / (a - b);
    x = min(x, n);
    cout << x << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}






