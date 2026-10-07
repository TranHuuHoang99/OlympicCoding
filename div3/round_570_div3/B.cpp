/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-07 16:09:45
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
void init(void) {

}
void solve(void) {
    cin >> n >> k;
    vector<int> arr(n);
    int min_val = INT32_MAX;
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        min_val = min(min_val, arr[i]);
        max_val = max(max_val, arr[i]);
    }
    if (abs(max_val - (min_val + k)) > k) {
        cout << -1 << '\n';
    } else {
        cout << min_val + k << '\n';
    }
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






