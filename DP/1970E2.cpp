/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-06-05 09:31:35
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;
struct Matrix {
    int row, col;
    vector<vector<int>> data;
    Matrix(const int _row, const int _col) {
        row = _row;
        col = _col;
        data.assign(_row+1, vector<int>(_col+1, 0ll));
    }
    Matrix operator *(const Matrix& other) {
        Matrix ret(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int sum = 0ll;
                for (int k = 0; k < other.row; k++) {
                    sum = (sum % MOD + (data[i][k] % MOD * other.data[k][j] % MOD) % MOD) % MOD;
                }
                ret.data[i][j] = sum;
            }
        }
        return ret;
    }
};
int m, n;
int S[110], L[110];
Matrix fast_power(const Matrix& a, const int b) {
    if (b <= 1) return a;
    Matrix ret = fast_power(a, b >> 1);
    ret = ret * ret;
    if (b & 1) ret = ret * a;
    return ret;
}
void solve(void) {
    cin >> m >> n;
    for (int i = 0; i < m; i++) cin >> S[i];
    for (int i = 0; i < m; i++) cin >> L[i];
    Matrix base(1, m+1);
    for (int i = 0; i < m; i++) {
        base.data[0][i] = ((S[0] % MOD * S[i] % MOD) % MOD +\
                          (S[0] % MOD * L[i] % MOD) % MOD +\
                          (L[0] % MOD * S[i] % MOD) % MOD) % MOD;
    }
    Matrix filter(m+1, m+1);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < m; i++) {
            filter.data[i][j] = (S[i] * S[j] + S[i] * L[j] + L[i] * S[j]);
        }
    }
    filter = fast_power(filter, n-1);
    Matrix ret = base;
    ret = ret * filter;
    int result = 0ll;
    for (int i = 0; i < m; i++) result = (result % MOD + ret.data[0][i] % MOD) % MOD;
    cout << result << endl;
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}