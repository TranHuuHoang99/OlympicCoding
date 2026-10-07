/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-07 15:57:03
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int sum_digits(int target) {
    int ret = 0;
    while (target) {
        ret += target % 10;
        target /= 10;
    }
    return ret;
}
void solve(void) {
    int n;
    cin >> n;
    while (sum_digits(n) % 4 != 0) {
        n++;
    }
    cout << n << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}






