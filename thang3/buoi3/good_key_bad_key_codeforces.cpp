/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 14.01.2025 21:10:10
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
ll A[N];
ll dp[N][32];
int n, k;

void solve(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= 30; j++) {
	 	 	dp[i][j] = LLONG_MIN;
	 	}
	}
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= 30; j++) {
	 	 	if (dp[i][j] != LLONG_MIN && i+1 <= n) {
	 	 	 	dp[i+1][j] = max(dp[i+1][j], dp[i][j] + A[i+1]/(ll)(pow(2,j)) - k);
	 	 	 	dp[i+1][min(30,j+1)] = max(dp[i+1][min(30,j+1)], dp[i][j] + A[i+1]/(ll)(pow(2,min(30,j+1)))); 
	 	 	}
	 	}
	}
	ll ret = LLONG_MIN;
	for (int i = 0; i <= 30; i++) ret = max(ret, dp[n][i]);
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
