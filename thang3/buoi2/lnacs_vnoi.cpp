/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 10.01.2025 19:45:04
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+10;
int A[N], B[N];
int dp[N][N];
int n, m;

void solve(void) {
	cin >> n >> m;
	for (int i = 2; i <= n+1; i++) cin >> A[i];
	for (int i = 2; i <= m+1; i++) cin >> B[i];
	for (int i = 2; i <= n+1; i++) {
	 	for (int j = 2; j <= m+1; j++) {
	 	 	if (A[i] == B[j]) {
	 	 	 	dp[i][j] = dp[i-2][j-2]+1;
	 	 	} else {
	 	 	 	dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	 	 	}
	 	}
	}
	cout << dp[n+1][m+1] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
