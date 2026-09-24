/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-24 22:11:06
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

string str;
string s_str;
void init(void) {
    for (char c = 'a'; c <= 'z'; c++) s_str += c;
}
void solve(void) {
    cin >> str;
    int len = str.size();
    sort(str.begin(), str.end());
    int idx = str[0] - 'a';
    if (str == s_str.substr(idx, len)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    init();
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}





