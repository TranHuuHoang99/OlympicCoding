#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

// Hàm chuẩn hóa giá trị modulo để tránh số âm
long long fix_mod(long long val) {
    return (val % MOD + MOD) % MOD;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<vector<long long>> A(n + 1, vector<long long>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> A[i][j];
            A[i][j] = fix_mod(A[i][j]);
        }
    }

    long long total_ans = 0;

    // CHÚ Ý: Tất cả các chỉ số i, j, x, y bên dưới đều tuân theo chuẩn 1-based (từ 1 đến n, m)

    // =========================================================================
    // TRƯỜNG HỢP 1: n lẻ, m lẻ
    // =========================================================================
    if (n % 2 != 0 && m % 2 != 0) {
        long long sum_odd_odd = 0;
        for (int i = 1; i <= n; i += 2) {
            for (int j = 1; j <= m; j += 2) {
                sum_odd_odd = (sum_odd_odd + A[i][j]) % MOD;
            }
        }
        total_ans = (sum_odd_odd * sum_odd_odd) % MOD;
    }
    // =========================================================================
    // TRƯỜNG HỢP 2: n lẻ, m chẵn
    // =========================================================================
    else if (n % 2 != 0 && m % 2 == 0) {
        vector<long long> P(m + 1, 0);
        for (int j = 1; j <= m; ++j) {
            for (int i = 1; i <= n; i += 2) {
                P[j] = (P[j] + A[i][j]) % MOD;
            }
        }
        long long sum_P_j_odd = 0;
        long long current_sum = 0;
        for (int col = 1; col <= m; ++col) {
            if (col % 2 == 0) {
                long long term = (P[col] * sum_P_j_odd) % MOD;
                current_sum = (current_sum + term) % MOD;
            } else {
                sum_P_j_odd = (sum_P_j_odd + P[col]) % MOD;
            }
        }
        total_ans = fix_mod(-2 * current_sum);
    }
    // =========================================================================
    // TRƯỜNG HỢP 3: n chẵn, m lẻ
    // =========================================================================
    else if (n % 2 == 0 && m % 2 != 0) {
        vector<long long> P_prime(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; j += 2) {
                P_prime[i] = (P_prime[i] + A[i][j]) % MOD;
            }
        }
        long long sum_P_i_odd = 0;
        long long current_sum = 0;
        for (int row = 1; row <= n; ++row) {
            if (row % 2 == 0) {
                long long term = (P_prime[row] * sum_P_i_odd) % MOD;
                current_sum = (current_sum + term) % MOD;
            } else {
                sum_P_i_odd = (sum_P_i_odd + P_prime[row]) % MOD;
            }
        }
        total_ans = fix_mod(-2 * current_sum);
    }
    // =========================================================================
    // TRƯỜNG HỢP 4: n chẵn, m chẵn
    // =========================================================================
    else {
        vector<long long> X(m + 1, 0); // Mảng dồn tích lũy của các hàng lẻ phía trước
        long long current_sum = 0;

        for (int k = 2; k <= n; k += 2) {
            // Cập nhật hàng lẻ ngay phía trước (k - 1) vào mảng bộ nhớ X
            for (int j = 1; j <= m; ++j) {
                X[j] = (X[j] + A[k - 1][j]) % MOD;
            }

            vector<long long> Y(m + 1);
            for (int j = 1; j <= m; ++j) Y[j] = A[k][j];

            // Tính toán nhanh Suffix Sum phục vụ cho độ phức tạp O(M)
            vector<long long> SuffY(m + 2, 0);
            for (int j = m; j >= 1; --j) {
                SuffY[j] = SuffY[j + 1];
                if (j % 2 == 0) SuffY[j] = (SuffY[j] + Y[j]) % MOD;
            }

            vector<long long> SuffX(m + 2, 0);
            for (int j = m; j >= 1; --j) {
                SuffX[j] = SuffX[j + 1];
                if (j % 2 == 0) SuffX[j] = (SuffX[j] + X[j]) % MOD;
            }

            // Tính Term 1 và Term 2 của hàng k
            long long term1 = 0, term2 = 0;
            for (int j = 1; j <= m; j += 2) {
                term1 = (term1 + X[j] * SuffY[j + 1]) % MOD;
                term2 = (term2 + Y[j] * SuffX[j + 1]) % MOD;
            }

            current_sum = (current_sum + term1 + term2) % MOD;
        }
        total_ans = (2 * current_sum) % MOD;
    }

    cout << total_ans << "\n";
}

int main() {
    // Tối ưu hóa tốc độ nhập xuất dữ liệu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
