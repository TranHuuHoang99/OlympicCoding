/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-23 13:04:19
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n;
string s;
void solve(void) {
    cin >> n >> s;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        int idx = i;
        while (idx < n && s[idx] == s[i]) idx++;
        string str = "RGB";
        str.erase(str.find(s[i]), 1);
        if (idx < n) str.erase(str.find(s[idx]), 1);
        for (int j = i+1; j < idx; j+=2) {
            ret++;
            s[j] = str[0];
        }
        i = idx-1;
    }
    cout << ret << '\n';
    cout << s << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





