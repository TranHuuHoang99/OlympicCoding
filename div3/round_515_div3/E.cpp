/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-19 18:55:45
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int MOD = 998244353;
const int N = 2e5+10;
int n, m;
string A, B;
int prefix[N];
int m_power(int a, int b) {
    int ret = 1ll;
    while (b) {
        if (b&1) ret = (ret % MOD * a % MOD) % MOD;
        a = (a % MOD * a % MOD) % MOD;
        b >>= 1;
    }
    return ret;
}
void solve(void) {
    cin >> n >> m;
    cin >> A;
    cin >> B;
    int max_size = max(A.size(), B.size());
    reverse(A.begin(), A.end());
    for (int i = A.size(); i < max_size; i++) A += '0';
    reverse(B.begin(), B.end());
    for (int i = 0; i < max_size; i++) {
        int val = (A[i] == '0') ? 0ll : 1ll;
        if (i == 0) {
            prefix[i] = val * m_power(2ll, i) % MOD;
        } else {
            prefix[i] = (prefix[i-1] % MOD + m_power(2ll, i) * val % MOD) % MOD;
        }
    }
    int ret = 0;
    for (int i = 0; i < m; i++) {
        int val = (B[i] == '0') ? 0ll : 1ll;
        ret = (ret % MOD + val * prefix[i] % MOD) % MOD;
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





