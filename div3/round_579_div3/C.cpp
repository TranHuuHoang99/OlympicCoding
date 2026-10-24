/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-28 15:12:14
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int len = 4e5+10;
int n;
int arr[len];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int gcd_value = arr[1];
    for (int i = 2; i <= n; i++) {
        gcd_value = __gcd(gcd_value, arr[i]);
    }
    int ret = 0;
    for (int i = 1; i <= sqrt(gcd_value); i++) {
        if (gcd_value % i == 0) {
            ret += 1;
            if (i * i != gcd_value) ret += 1;
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






