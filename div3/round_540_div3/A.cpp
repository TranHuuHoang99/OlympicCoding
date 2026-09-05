/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-05 12:40:25
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

void solve(void) {
    int q;
    cin >> q;
    int n, a, b;
    while (q--) {
        cin >> n >> a >> b;
        int cost1 = a * n;
        int cost2 = n / 2 * b;
        if (n % 2 == 1) {
            cost2 += a;
        }
        cout << min(cost1, cost2) << '\n';
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





