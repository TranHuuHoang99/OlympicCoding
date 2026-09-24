/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-23 11:10:08
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
void solve(void) {
    cin >> n >> m;
    if (m % n != 0) {
        cout << -1 << '\n';
        return;
    }
    int rem = m / n;
    int ret = 0;
    while (rem > 1) {
        if (rem % 2 == 0) {
            rem /= 2;
            ret++;
        } else if (rem % 3 == 0) {
            rem /= 3;
            ret++;
        } else {
            cout << -1 << '\n';
            return;
        }
    }
    cout << ret << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





