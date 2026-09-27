/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-28 15:22:02
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
const int M = 2e3+10;
int n, m, k;
int A[N];
int prefix[N];
int offer[N];
int F[N];
void solve(void) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> A[i];
    sort(A+1, A+1+n);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + A[i];
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        if (x <= k) {
            offer[x] = max(offer[x], y);
        }
    }
    for (int i = 0; i <= k; i++) F[i] = LLONG_MAX;
    F[0] = 0;
    for (int i = 0; i < k; i++) {
        if (F[i] == LLONG_MAX) continue;
        // case we buy this shovel and not use any offer
        F[i+1] = min(F[i+1], F[i] + A[i+1]);
        for (int x = 1; x <= k; x++) {
            if (i + x > k) break;
            int y = offer[x];
            // case we buy this shovel using current offer
            int discount = prefix[i+x] - prefix[i+y];
            F[i+x] = min(F[i+x], F[i] + discount);
        }
    }
    cout << F[k] << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





