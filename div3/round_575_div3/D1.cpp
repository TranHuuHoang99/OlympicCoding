/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-22 15:26:10
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
        for (int i = 0; i+k <= n; i++) {
            int diff = 0;
            for (int j = i; j < i+k; j++) {
                if (sample_str[j-i] != str[j]) {
                    diff += 1;
                }
            }
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






