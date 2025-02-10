/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 05.02.2025 13:42:30
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int n;
ll W[N];
// first array is ants, second array is maximum ant we can get due to 1e9 weight
// second array note: 1 1 1 1 1 1 6 6 6 6 6 6 36 36 36 36 36 36 216 216 216 ... 1e9
// log6(1e9) = 12 => 12 * 6 = 72 (maximum ant stack) => so we let second array is 200 to calculate
// solution for this is we get the minimum weight of ant with the same size of stack ant
ll dp[N][200];

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> W[i];
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= 190; j++) {
	 		dp[i][j] = LLONG_MAX;
	 	}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j <= 190; j++) {
	 	 	if (dp[i][j] == LLONG_MAX) continue;
	 	 	// we dont get stack of next ant
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			if (dp[i][j] <= 6ll*W[i+1]) {
			 	dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + W[i+1]);
			}
	 	}
	}
	int ret = 0;
	for (int i = 0; i <= 190; i++) {
	 	if (dp[n][i] != LLONG_MAX) {
	 	 	ret = max(ret, i);
	 	}
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
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
	 	solve();
	}

	return 0;
}
