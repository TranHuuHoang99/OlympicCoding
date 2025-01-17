/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 12.01.2025 13:18:39
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 420;
ll A[N];
ll dp[N][N];
ll cost[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cost[i] = cost[i-1] + A[i];
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= n; j++) {
	 	 	if (i == j) {
	 	 	 	dp[i][j] = 0;
	 	 	} else {
	 	 	 	dp[i][j] = LLONG_MAX;
	 	 	}
	 	}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = i+1; j <= n; j++) {
		 	ll diff = cost[j] - cost[i-1];
		 	for (int k = i; k < j; k++) {
		 	 	dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + diff);
		 	}
		}
	}
	cout << dp[1][n] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
