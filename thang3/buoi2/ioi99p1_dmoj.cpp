/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 10.01.2025 20:40:02
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 110;
int A[N][N];
int dp[N][N];
int idx[N];
int n, m;

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	cin >> A[i][j];
	 	}
	}
	for (int i = 1; i <= n; i++) {
	 	for (int j = 0; j <= m; j++) {
	 	 	dp[i][j] = -5010;
	 	}
	}
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]+A[i][j]);
	 	}
	}
	cout << dp[n][m] << endl;
	int i = n, j = m;
	while (i) {
	 	if (dp[i][j] == dp[i-1][j-1] + A[i][j]) {
	 	 	idx[i] = j;
	 	 	i--;
	 	 	j--;
	 	} else {
	 	 	j--;
	 	}
	}
	for (int i = 1; i <= n; i++) cout << idx[i] << ' ';
	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
