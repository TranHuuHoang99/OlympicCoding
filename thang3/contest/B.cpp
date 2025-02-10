/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 25.01.2025 23:00:16
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+500;
const ll M = 110;
int n, k;
int A[N];
int dp[N];

void solve(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) dp[i] = INT32_MAX;
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; i+j <= n && j <= k; j++) {
	 	 	if (dp[i] == INT32_MAX) continue;
	 	 	dp[i+j] = min(dp[i+j], dp[i] + abs(A[i+j] - A[i]));
	 	}
	}
	cout << dp[n] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
