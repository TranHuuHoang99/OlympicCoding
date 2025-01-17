/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 13.01.2025 18:31:05
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+10;
ll A[N][N];
ll dp[N][N][2];
int m, n;

void solve(void) {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
	 	for (int j = 1; j <= n; j++) {
	 	 	cin >> A[i][j];
	 	}
	}
	for (int i = 1; i <= m; i++) {
	 	for (int j = 1; j <= n; j++) {
	 	 	for (int k = 0; k < 2; k++) {
	 	 	 	dp[i][j][k] = LLONG_MAX;
	 	 	}
	 	}
	}
	for (int i = 1; i <= m; i++) {
	 	for (int j = 1; j <= n; j++) {
	 	 	dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1] + A[i][j]);
	 	 	dp[i][j][1] = min(dp[i][j-1][1], dp[i][j-1][0] + A[i][j]);
	 	}
	}
	cout << min(dp[m][n][0], dp[m][n][1]) << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	int t;
	cin >> t;
	while (t--) {
	 	solve();
	}

	return 0;
}
