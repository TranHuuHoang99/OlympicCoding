/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 23.01.2025 19:50:05
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int n, w;
int W[N], V[N];
int dp[110][N];

void solve(void) {
 	cin >> n >> w;
 	int max_val = 0;
 	for (int i = 1; i <= n; i++) {
 	 	cin >> W[i] >> V[i];
 	 	max_val += V[i];
 	}
 	for (int i = 0; i <= n; i++) {
 	 	for (int j = 0; j <= max_val; j++) {
 	 	 	dp[i][j] = INT32_MAX;
 	 	}
 	}
 	dp[0][0] = 0;
 	for (int i = 0; i < n; i++) {
 	 	for (int j = 0; j <= max_val; j++) {
 	 	 	if (dp[i][j] == INT32_MAX) continue;
 	 	 	dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
 	 	 	if (dp[i][j] + W[i+1] <= w) {
 	 	 	 	dp[i+1][j+V[i+1]] = min(dp[i+1][j+V[i+1]], dp[i][j] + W[i+1]);
 	 	 	}
 	 	}
 	}
 	int ret = 0;
 	for (int i = 0; i <= max_val; i++) {
 	 	if (dp[n][i] <= w) {
 	 	 	ret = max(ret, i);
 	 	}
 	}
 	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
