/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 15.04.2025 20:26:46
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e2+10;
const ll MOD = 1e9+7;
int n, A[N];
ll dp[N][80];

void solve(void) {
	cin >> n;
	for (int i = 0; i <= 100; i++) {
	 	for (int j = 0; j <= 70; j++) {
	 	 	dp[i][j] = 0ll;
	 	}
	}
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
	}
	dp[0][0] = 1ll; // 0C0 = 1, combination 0 of 0
	for (int i = 0; i < n; i++) {
	 	for (int g = 0; g <= 70; g++) {
	 		if (dp[i][g] == 0) continue;
			// dont add i+1 to array
			dp[i+1][g] += dp[i][g] % MOD;
			dp[i+1][g] %= MOD;
			int new_g = g == 0 ? A[i+1] : __gcd(g, A[i+1]);
			dp[i+1][new_g] += dp[i][g] % MOD;
			dp[i+1][new_g] %= MOD;
	 	}
	}
	ll ret = 0ll;
	for (int g = 1; g <= 70; g++) {
	 	ret += (1ll * g % MOD * dp[n][g] % MOD) % MOD;
	}
	cout << (ret % MOD) << endl;
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
	 	solve();
	}

	return 0;
}
