/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-16 19:33:19
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 16;
const int M = 1e4+10;
int n, m;
int A[N+10][M];
bool F[(1<<N)+1][N+5];
int diff[N+5][N+5];
int diff_cycle[N+5][N+5];
bool check(int target) {
    int full_mask = (1 << n) - 1;
    for (int start = 0; start < n; start++) {
        memset(F, false, sizeof(F));
        F[(1<<start)][start] = true;
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int u = 0; u < n; u++) {
                if (!(mask & (1 << u)) || !F[mask][u]) continue;
                for (int v = 0; v < n; v++) {
                    if (mask & (1 << v)) continue;
                    int n_mask = mask | (1 << v);
                    F[n_mask][v] |= (diff[u][v] >= target);
                }
            }
        }
        for (int stop = 0; stop < n; stop++) {
            if (F[full_mask][stop] && (diff_cycle[start][stop] >= target))
                return true;
        }
    }
    return false;
}
void solve(void) {
    cin >> n >> m;
    int right = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            right = max(right, A[i][j]);
        }
    }
    // pre-process
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (u == v) continue;
            int min_val = INT32_MAX;
            for (int j = 0; j < m; j++) {
                min_val = min(min_val, abs(A[u][j] - A[v][j]));
            }
            diff[u][v] = min_val;
        }
    }
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            int min_val = INT32_MAX;
            for (int j = 0; j < m-1; j++) {
                min_val = min(min_val, abs(A[u][j] - A[v][j+1]));
            }
            diff_cycle[u][v] = min_val;
        }
    }
    int left = 0;
    int ret = 0;
    while (left <= right) {
        int mid = (left+right)/2;
        if (check(mid)) {
            ret = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
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





