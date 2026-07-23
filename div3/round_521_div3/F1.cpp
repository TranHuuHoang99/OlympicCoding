/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-27 20:41:32
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 220;
int n, k, x;
int A[N];
// F[i][j] is the maximum beauty of the pictures
// when we already had i number of pictures
// and the j'th picture is the choosen for the next
int F[N][N];
void solve(void) {
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= n; j++) {
            F[i][j] = LLONG_MIN;
        }
    }
    // we not yet choose any pic and pic at zero does not exist
    F[0][0] = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 1; j <= n; j++) {
            int max_val = LLONG_MIN;
            for (int idx = max(0ll, j-k); idx < j; idx++) {
                max_val = max(max_val, F[i][idx]);
            }
            if (max_val != LLONG_MIN) {
                F[i+1][j] = max_val + A[j];
            }
        }
    }
    int ret = LLONG_MIN;
    for (int i = n-k+1; i <= n; i++) {
        if (i >= 1) {
            ret = max(ret, F[x][i]);
        }
    }
    if (ret == LLONG_MIN) {
        cout << -1 << '\n';
    } else {
        cout << ret << '\n';
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





