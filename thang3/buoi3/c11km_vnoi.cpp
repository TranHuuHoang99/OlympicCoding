/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 14.01.2025 20:05:21
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+10;
int A[N];
int dp[N][N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= n; j++) {
	 	 	dp[i][j] = INT32_MAX;
	 	}
	}
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= n; j++) {
	 	 	if (dp[i][j] != INT32_MAX) {
	 	 		// buy with cash
	 	 	 	if (A[i+1] <= 100) {
	 	 	 	 	dp[i+1][j] = min(dp[i+1][j], dp[i][j] + A[i+1]);
	 	 	 	} else {
	 	 	 	 	dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + A[i+1]);
	 	 	 	}
	 	 	 	// buy for free
	 	 	 	if (j > 0) {
	 	 	 	 	dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j]);
	 	 	 	}
	 	 	}
	 	}
	}
	int ret = INT32_MAX;
	for (int i = 0; i <= n; i++) ret = min(ret, dp[n][i]);
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
