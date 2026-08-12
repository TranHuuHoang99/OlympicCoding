/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-12 23:57:53
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    int sum = (n * (n+1)) / 2;
    if (sum % 2 == 0) {
        cout << "0\n";
    } else {
        cout << "1\n";
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





