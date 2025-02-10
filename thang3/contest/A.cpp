/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 25.01.2025 19:34:52
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m, p;
int dp[32][32][52];

void solve(void) {
	n = 30;
	m = 30;
	p = 50;
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= m; j++) {
	 	 	for (int k = 1; k <= p; k++) {
	 	 	 	dp[i][j][k] = i*j == k ? 0 : 1e3;
	 	 	}
	 	}
	}
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	for (int k = 1; k <= p; k++) {
	 	 	 	for (int cut = 1; cut < i; cut++) {
	 	 	 	 	for (int left = 1; left <= k; left++) {
	 	 	 	 	 	dp[i][j][k] = min(dp[i][j][k], dp[i-cut][j][left] + dp[cut][j][k-left] + j*j);
	 	 	 	 	}
	 	 	 	}
	 	 	 	for (int cut = 1; cut < j; cut++) {
	 	 	 	 	for (int left = 1; left <= k; left++) {
	 	 	 	 	 	dp[i][j][k] = min(dp[i][j][k], dp[i][j-cut][left] + dp[i][cut][k-left] + i*i);
	 	 	 	 	}
	 	 	 	}
	 	 	}
	 	}
	}
	int t;
	cin >> t;
	while (t--) {
	 	int a,b,c;
	 	cin >> a >> b >> c;
	 	cout << dp[a][b][c] << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	solve();

	return 0;
}
