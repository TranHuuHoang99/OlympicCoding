#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;
int n, m;
ll dp[1001][1 << 10];

void dfs(int col, int cur_mask, int idx, int next_mask) {
	if (idx == n) {
		dp[col+1][next_mask] = (dp[col+1][next_mask] + dp[col][cur_mask]) % MOD;
		return;	
	}

	if (cur_mask & (1 << idx)) {
		dfs(col, cur_mask, idx+1, next_mask);
	} else {
		// put 1x2 tile to current position which is (idx)
		dfs(col, cur_mask, idx+1, next_mask | (1 << idx));
		// put 2x1 tile to current position which is (idx)
		if (idx + 1 < n && (!(cur_mask & (1 << (idx+1))))) {
			dfs(col, cur_mask, idx+2, next_mask);
		}
	}
}

void solve(void) {
	cin >> n >> m;
	dp[0][0] = 1;

	for (int col = 0; col < m; col++) {
		for (int mask = 0; mask < (1 << n); mask++) {
			if (dp[col][mask] > 0) {
				dfs(col, mask, 0, 0);
			}
		}
	}

	cout << dp[m][0] % MOD << endl;
}
  
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
}
