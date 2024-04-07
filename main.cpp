#include <bits/stdc++.h>
using namespace std;

int64_t minCost(int N, int B, int C, vector<int>& P, vector<int>& F, vector<int>& D) {
    
    vector<vector<int64_t>> dp(N + 1, vector<int64_t>(C + 1, INT64_MAX));
    dp[0][B]= 0; 

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= C; ++j) {
            if (j >= D[i - 1] && dp[i - 1][j]!= INT64_MAX) {
                dp[i][j - D[i - 1]] = min(dp[i][j - D[i - 1]], dp[i - 1][j]);
            }

            if (dp[i - 1][j] != INT64_MAX) {
                int chargeAfter = min(j + P[i - 1], C); 
                dp[i][chargeAfter] = min(dp[i][chargeAfter], dp[i - 1][j]+ D[i - 1]* F[i - 1]);
            }
        }
    }

    int64_t min_cost = INT64_MAX;
    for (int j = B; j <= C; ++j) {
        if (dp[N][j] < min_cost) {
            min_cost = dp[N][j];
        }
    }


    return min_cost;
}

int main() {
    vector<int64_t> result;

    int N = 0, B = 0, C = 0;
    std::cin >> N >> B >> C;

    std::vector<int> P(N,0), F(N,0), D(N,0);

    for (int i = 0; i < N; ++i) {
        std::cin >> P[i];
    }

    for (int i = 0; i < N; ++i) {
        std::cin >> F[i];
    }

    for (int i = 0; i < N; ++i) {
        std::cin >> D[i];
    }

    int64_t minimumCost = minCost(N, B, C, P, F, D);

    return 0;
}