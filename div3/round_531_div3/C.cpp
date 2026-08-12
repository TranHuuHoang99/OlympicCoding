/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-13 22:31:45
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n, x, y;
void solve(void) {
    cin >> n >> x >> y;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        if (val <= x) cnt++;
    }
    if (x > y) {
        cout << n << '\n';
        return;
    }
    if (cnt % 2 != 0) {
        cout << cnt / 2 + 1 << '\n';
    } else {
        cout << cnt / 2 << '\n';
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





