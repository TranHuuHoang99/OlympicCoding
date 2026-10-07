/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-19 15:08:00
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;
int n, m;
vector<int> v_matrix;
vector<int> f_suffix[2][2];
void solve(void) {
    cin >> n >> m;
    int row_stride = m+2;
    int total_allocated = (n+2) * row_stride;
    v_matrix.clear();
    v_matrix.resize(total_allocated);
    for (int r = 0; r <= 1; r++) {
        for (int c = 0; c <= 1; c++) {
            f_suffix[r][c].clear();
            f_suffix[r][c].resize(total_allocated);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int val;
            cin >> val;
            v_matrix[i*row_stride+j] = (val % mod + mod) % mod;
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            int cur = i * row_stride + j;
            int down = (i+1) * row_stride + j;
            int right = i * row_stride + (j+1);
            int diag = (i+1) * row_stride + (j+1);
            for (int r = 0; r <= 1; r++) {
                for (int c = 0; c <= 1; c++) {
                    f_suffix[r][c][cur] = (f_suffix[r][c][down] % mod + f_suffix[r][c][right] % mod - f_suffix[r][c][diag] % mod + mod) % mod;
                }
            }
            f_suffix[i%2][j%2][cur] = (f_suffix[i%2][j%2][cur] % mod + v_matrix[cur] % mod) % mod;
        }
    }
    /*
        we using two fixed pair in matrix (i,j) , (x,y) in a different square each other
        the total sub-matrix calculate byte:
            - sum(1 <= min(i, x)) x sum(max(i, x) <= n) x sum(1 <= min(j, y)) x sum(max(j, y) <= m)
    */
    int row_parity = n % 2;
    int col_parity = m % 2;
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int n_i_n_j = (i+1)*row_stride+(j+1);
            int i_j = i*row_stride+j;
            int n_i_j = (i+1)*row_stride+j;
            int i_n_j = i*row_stride+(j+1);
            if (i % 2 == 1) {
                // case x > i and y > j
                // so j must be odd
                if (j % 2 == 1) {
                    int val = f_suffix[row_parity][col_parity][n_i_n_j];
                    val = (val % mod * v_matrix[i_j] % mod) % mod;
                    ret = (ret % mod + val % mod) % mod;
                }
                // case x > i and y < j
                // so j must be the same parity with col_parity and y should be odd
                if (j % 2 == col_parity) {
                    int val = (f_suffix[row_parity][1][(i+1)*row_stride+1] % mod - f_suffix[row_parity][1][n_i_j] % mod + mod) % mod;
                    val = (val % mod * v_matrix[i_j] % mod) % mod;
                    ret = (ret % mod + val % mod) % mod;
                }
                // case x > i and y == j
                // so j must be odd and j must be the same parity with m => m must be odd as well
                if (j % 2 == 1 && j % 2 == col_parity) {
                    int val = (f_suffix[row_parity][col_parity][n_i_j] % mod - f_suffix[row_parity][col_parity][n_i_n_j] % mod + mod) % mod;
                    val = (val % mod * v_matrix[i_j] % mod) % mod;
                    ret = (ret % mod + val % mod) % mod;
                }
            }
            if (i % 2 == 1 && n % 2 == 1) {
                // case x == i and j < y
                // so j must be odd and y should be the same parity with m
                if (j % 2 == 1) {
                    int val = (f_suffix[1][col_parity][i_n_j] % mod - f_suffix[1][col_parity][n_i_n_j] % mod + mod) % mod;
                    val = (val % mod * v_matrix[i_j] % mod) % mod;
                    ret = (ret % mod + val % mod) % mod;
                }
            }
        }
    }
    ret = (ret % mod * 2 % mod) % mod;
    // case x == i and y == j
    // so i must be odd, x must be odd
    // j must be odd, y must be odd
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i % 2 == 1 && (i % 2 == row_parity) && j % 2 == 1 && (j % 2 == col_parity)) {
                ret = (ret % mod + (v_matrix[i*row_stride+j] % mod * v_matrix[i*row_stride+j] % mod) % mod) % mod;
            }
        }
    }
    ret %= mod;
    if ((n+m) % 2 == 1) {
        ret = (mod - ret) % mod;
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}





 