/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-28 16:11:11
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(void) {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string remain_str = s.substr(0, i) + s.substr(j+1);
            int idx = 0;
            for (int k = 0; k < remain_str.size(); k++) {
                if (remain_str[k] == t[idx]) {
                    idx++;
                }
                if (idx == m) break;
            }
            if (idx == m) {
                ret = max(ret, j - i + 1);
            }
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






