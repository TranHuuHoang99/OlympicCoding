/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-09 13:09:39
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n;
string str;
void solve(void) {
    cin >> n;
    cin >> str;
    string ret = "";
    int cnt = 1;
    int idx = 0;
    while (idx < n) {
        int cur_idx = 0;
        ret += str[idx];
        while (cur_idx < cnt) {
            idx++;
            cur_idx++;
        }
        cnt++;
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





