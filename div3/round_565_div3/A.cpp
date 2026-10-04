/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-04 12:55:10
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n;
void solve(void) {
    cin >> n;
    int ret = 0;
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
            ret++;
        } else if (n % 3 == 0) {
            n /= 3;
            n *= 2;
            ret++;
        } else if (n % 5 == 0) {
            n /= 5;
            n *= 4;
            ret++;
        } else {
            break;
        }
    }
    if (n > 1) {
        cout << -1 << '\n';
    } else {
        cout << ret << '\n';
    }
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





