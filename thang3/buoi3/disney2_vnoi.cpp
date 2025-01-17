/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 17.01.2025 23:14:28
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 210;
const int oo = 3e7+10;
int n;
int A[N][N];
int dp[N][N];

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= n; j++) {
	 	 	cin >> A[i][j];
	 	}
	}
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= n; j++) {
	 	 	dp[i][j] = oo;
	 	}
	}
	dp[1][1] = 0;
	for (int i = 1; i < n; i++) {
	 	for (int j = 1; j <= i; j++) {
	 	 	if (dp[i][j] != oo) {
	 	 	 	dp[i+1][j] = min(dp[i+1][j], dp[i][j] + A[i][i+1]);
	 	 	 	dp[i+1][i] = min(dp[i+1][i], dp[i][j] + A[j][i+1]);
	 	 	}
	 	}
	}
	int ret = oo;
	for (int i = 1; i <= n; i++) {
	 	ret = min(ret, dp[n][i] + A[n][1] + A[i][1]);
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
