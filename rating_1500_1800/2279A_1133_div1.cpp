/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-08 00:00:18
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> diff(n-1);
    for (int i = 0; i < n-1; i++) {
        diff[i] = abs(arr[i] - arr[i+1]);
    }
    vector<int> prefix(n-1);
    prefix[0] = diff[0];
    for (int i = 1; i < n-1; i++) {
        prefix[i] = max(prefix[i-1], diff[i]);
    }
    vector<int> suffix(n-1);
    suffix[n-2] = diff[n-2];
    for (int i = n-3; i >= 0; i--) {
        suffix[i] = max(suffix[i+1], diff[i]);
    }
    int ret = prefix[n-2];
    for (int i = 0; i < n; i++) {
        int cur_max = 0;
        if (i-2 >= 0) cur_max = max(cur_max, prefix[i-2]);
        if (i+2 < n-1) cur_max = max(cur_max, suffix[i+2]);
        if (i-1 >= 0) cur_max = max(cur_max, abs(2*arr[i] - arr[i-1]));
        if (i+1 < n) cur_max = max(cur_max, abs(2*arr[i] - arr[i+1]));
        ret = min(ret, cur_max);
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





