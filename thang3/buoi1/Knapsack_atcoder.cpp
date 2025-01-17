/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 08.01.2025 20:57:52
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 110;
const ll M = 1e5+1;
ll dp[N][M];
int n, w;
int W[N], V[N];

void solve(void) {
	cin >> n >> w;
	for (int i = 1; i <= n; i++) {
	 	cin >> W[i] >> V[i];
	}
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= w; j++) {
	 	 	dp[i][j] = dp[i-1][j];
	 	 	if (j >= W[i]) {
	 	 	 	dp[i][j] = max(dp[i][j], dp[i-1][j-W[i]]+V[i]);
	 	 	}
	 	}
	}
	cout << dp[n][w] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);                                                0
	
	solve();

	return 0;
}
