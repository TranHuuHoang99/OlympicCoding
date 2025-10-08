#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

vector<vector<long long>> mat_mul(const vector<vector<long long>>& a, const vector<vector<long long>>& b) {
    int n = a.size();
    int m = b[0].size();
    int p = a[0].size();
    vector<vector<long long>> result(n, vector<long long>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < p; k++) {
            if (a[i][k] == 0) continue;
            for (int j = 0; j < m; j++) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}

vector<vector<long long>> mat_pow(vector<vector<long long>> matrix, long long n) {
    vector<vector<long long>> result;
    bool has_result = false;

    while (n > 0) {
        if (n % 2 == 1) {
            if (!has_result) {
                result = matrix;
                has_result = true;
            } else {
                result = mat_mul(result, matrix);
            }
        }
        n /= 2;
        matrix = mat_mul(matrix, matrix);
    }

    return result;
}

vector<vector<long long>> a3 = {
    {2262},
    {78},
    {0},
    {3645},
    {130},
    {5},
    {15813},
    {546},
    {21},
    {20160}
};

vector<vector<long long>> M = {
    {0, 0, 0, 3, 9, 0, 3, 9, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {5, 0, -125, 5, 0, 0, 5, 0, -125, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {21, 0, -21, 21, 0, -21, 21, 0, -20, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {5 + 21, 0, -125 - 21, 5 + 21, 0, -21, 5 + 21, 0, -125 - 20, 1}
};

long long subsum(long long n) {
    if (n == 0) return 0;
    else if (n == 1) return 26;
    else if (n == 2) return 702;
    else if (n == 3) return 20160;

    auto Mp = mat_pow(M, n - 3);
    auto res = mat_mul(Mp, a3);
    long long val = res.back().back() % MOD;
    if (val < 0) val += MOD;
    return val;
}

// solve(a, b)
long long solve(long long a, long long b) {
    long long ans = (subsum(b) - subsum(a - 1)) % MOD;
    if (ans < 0) ans += MOD;
    return ans;
}

// ================== DEMO ==================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    cin >> a >> b;
    cout << solve(a, b) << "\n";
    return 0;
}
