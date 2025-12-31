/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-11-09 09:45:22
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
const ll M = 1e3+10;
int n, q;
ll H[N], W[N];
ll F[M][M];
ll sum[M][M];
void solve(void) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> H[i] >> W[i];
    }
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            F[i][j] = 0ll;
            sum[i][j] = 0ll;
        }
    }
    for (int i = 1; i <= n; i++) {
        F[H[i]][W[i]] += 1ll * (H[i] * W[i]);
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + F[i][j];
        }
    }
    for (int i = 1; i <= q; i++) {
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        cout << sum[hb-1][wb-1] - sum[hb-1][ws] - sum[hs][wb-1] + sum[hs][ws] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}





