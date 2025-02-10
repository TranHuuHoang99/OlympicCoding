/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 24.01.2025 20:13:42
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 110; // maximum number of customer
const ll M = 1e5+10; // maximum time of service
int n;
int A[N], B[N];
// first array is order of customer, second array time of second employee'service
int dp[N][M];

void solve(void) {
	cin >> n;
	int max_val = 0;
	int temp = 0;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
	 	temp += A[i];
	}
	max_val = max(max_val, temp);
	temp = 0;
	for (int i = 1; i <= n; i++) {
	 	cin >> B[i];
	 	temp += B[i];
	}
	max_val = max(max_val, temp);
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= max_val; j++) {
	 	    dp[i][j] = INT32_MAX;
	 	}	
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j <= max_val; j++) {
	 	 	if (dp[i][j] == INT32_MAX) continue;
	 	 	// if first employee serve, then time of second employee is not change
	 	 	dp[i+1][j+A[i+1]] = min(dp[i+1][j+A[i+1]], dp[i][j]);
	 	 	// second employee serve
	 	 	dp[i+1][j] = min(dp[i+1][j], dp[i][j] + B[i+1]);
	 	}
	}
	int ret = INT32_MAX;
	for (int i = 0; i <= max_val; i++) {
	 	ret = min(ret, max(i,dp[n][i]));
	}
	cout << ret << endl;
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
