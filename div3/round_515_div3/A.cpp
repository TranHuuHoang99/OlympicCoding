/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-17 21:49:06
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

void solve(void) {
    int des, period, u, v;
    cin >> des >> period >> u >> v;
    if (u <= des && des <= v) { 
        cout << (u-1) / period << '\n';
        return;
    }
    if (des < u) {
        cout << des / period << '\n';
        return;
    }
    if (des > v) {
        int left_most = (u-1) / period;
        int right_most = v / period;
        int mid = right_most - left_most;
        cout << max(0ll, (des / period) - mid) << endl;
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}





