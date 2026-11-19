/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-19 11:22:44
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end());
    vector<bool> is_balance(35, false);
    int max_val = *max_element(s.begin(), s.end());
    for (int i = 1; i <= 1024; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            temp.push_back(s[j] ^ i);
        }
        sort(temp.begin(), temp.end());
        if (temp == s) {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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






