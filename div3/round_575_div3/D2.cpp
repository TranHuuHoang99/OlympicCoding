/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-22 16:32:18
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(void) {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    string pattern_str = "RGB";
    int ret = k;
    for (int offset = 0; offset <= 2; offset++) {
        string sample_str = "";
        for (int i = 0; i < k; i++) {
            sample_str += pattern_str[(i+offset)%3];
        }
        int diff = 0;
        for (int i = 0; i < k; i++) {
            if (str[i] != sample_str[i]) diff++;
        }
        ret = min(ret, diff);
        for (int i = k; i < n; i++) {
            // remove the ex-character out of current window
            if (str[i-k] != pattern_str[(i-k+offset)%3]) diff--;
            // add new character into current window
            if (str[i] != pattern_str[(i+offset)%3]) diff++;
            ret = min(ret, diff);
        }
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






