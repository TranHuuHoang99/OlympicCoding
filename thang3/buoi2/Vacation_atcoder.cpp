/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 10.01.2025 20:11:01
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int A[N][4];
int dp[N][4];
int n;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= 3; j++) cin >> A[i][j];
	}
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= 3; j++) {
	 	 	for (int k = 1; k <= 3; k++) {
	 	 	 	if (k == j) continue;
	 	 	 	dp[i][j] = max(dp[i][j], dp[i-1][k]+A[i][j]);
	 	 	}
	 	}
	}
	int ret = INT32_MIN;
	for (int i = 1; i <= 3; i++) {
	 	ret = max(ret, dp[n][i]);
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
