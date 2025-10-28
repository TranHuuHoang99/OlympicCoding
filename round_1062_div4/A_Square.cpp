/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-10-28 21:35:51
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a, b, c, d;
void solve() {
    cin >> a >> b >> c >> d;
    if (a == b && b == c && c == d) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}