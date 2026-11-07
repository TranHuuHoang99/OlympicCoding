/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-07 15:39:04
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
        int max_val = a * val / b;
        int ret = 0;
        int left = 0;
        int right = val;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (mid * a / b == max_val) {
                ret = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << val - ret << ' ';
    }
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





