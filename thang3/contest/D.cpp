/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 26.01.2025 00:02:01
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e2+100;
const ll M = 1e5+100;
int n, h;
// A[N] is weight B[N] is value
ll A[N];
int B[N];
ll dp[N][M][2];
ll w;

void solve(void) {
	cin >> n >> w >> h;
	int max_val = 0;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i] >> B[i];
	 	max_val += B[i];
	}
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= max_val; j++) {
	 	 	for (int k = 0; k <= 1; k++) {
	 	 	 	dp[i][j][k] = INT32_MAX;
	 	 	}
	 	}
	}
	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j <= max_val; j++) {
	 	 	for (int k = 0; k <= 1; k++) {
	 	 	 	if (dp[i][j][k] == INT32_MAX) continue;
	 	 	 	dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
	 	 	 	dp[i+1][j+B[i+1]][k] = min(dp[i+1][j+B[i+1]][k], dp[i][j][k] + A[i+1]);
	 	 	 	if (k == 0 && A[i+1] <= h) {
	 	 	 	 	dp[i+1][j+B[i+1]][1] = min(dp[i+1][j+B[i+1]][1], dp[i][j][0]);
	 	 	 	}
	 	 	}
	 	}
	}
	int ret = INT32_MIN;
	for (int i = 0; i <= max_val; i++) {
	 	for (int j = 0; j <= 1; j++) {
	 	 	if (dp[n][i][j] <= w) ret = max(ret, i);
	 	}
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	solve();

	return 0;
}
