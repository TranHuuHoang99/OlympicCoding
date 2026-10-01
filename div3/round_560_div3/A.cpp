/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-01 14:08:08
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, x, y;
string str;
void solve(void) {
    cin >> n >> x >> y;
    cin >> str;
    reverse(str.begin(), str.end());
    int ret = 0;
    for (int i = 0; i < x; i++) {
        if (i == y) {
            if (str[i] != '1') ret++;
        } else {
            if (str[i] == '1') ret++;
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





