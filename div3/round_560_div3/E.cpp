/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-02 12:40:34
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
const int N = 2e5+10;
int n;
int A[N], B[N], C[N];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) cin >> B[i];
    for (int i = 1; i <= n; i++) {
        C[i] = A[i] * i * (n - i + 1ll);
    }
    sort(C+1, C+1+n);
    sort(B+1, B+1+n, [&] (int a, int b) -> bool {
        return a > b;
    });
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        ret = (ret % mod + (C[i] % mod * B[i] % mod) % mod) % mod;
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}






