/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 16.01.2025 21:20:44
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e6+10;
int A[N];
ll dp[N][2]; // 0 is minus, 1 is plus
int n;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 0; i <= n; i++) {
	 	dp[i][0] = LLONG_MIN;
	 	dp[i][1] = LLONG_MIN;
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j <= 1; j++) {
	 	 	if (dp[i][j] != LLONG_MIN) {
				dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
				dp[i+1][1-j] = max(dp[i+1][1-j], dp[i][j] + 1ll * (j == 0 ? 1 : -1) * A[i+1]);
	 	 	}
	 	}
	}
	cout << max(dp[n][0], dp[n][1]) << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
