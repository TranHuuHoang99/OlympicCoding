/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 06.12.2024 22:29:58
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	string a, b, c;
	cin >> a >> b >> c;
	int n = a.size();
	int m = b.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, INT32_MAX));
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= m; j++) {
	 	 	int k = i+j;
	 	 	if (k > c.size()) continue;
	 	 	if (i < n) {
	 	 	 	int temp = int(a[i] != c[k]);
	 	 	 	dp[i+1][j] = min(dp[i+1][j], dp[i][j]+temp);
	 	 	}
	 	 	if (j < m) {
	 	 	 	int temp = int(b[j] != c[k]);
	 	 	 	dp[i][j+1] = min(dp[i][j+1], dp[i][j]+temp);
	 	 	}
	 	}
	}
	cout << dp[n][m] << endl;
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
