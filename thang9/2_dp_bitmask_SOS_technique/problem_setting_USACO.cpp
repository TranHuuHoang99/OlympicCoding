/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-18 20:27:28 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9+7;
const ll N = 1e5+10;
const ll max_mask = (1 << 20) + 10;
int n, m;
string str[N];
ll cnt[max_mask];
ll dp[max_mask];
ll sum_dp[max_mask][25];
ll inv_fact[N];
ll fact[N];
ll prob[N];
ll sum_inv_fact[N];

ll fast_power(ll a, ll b) {
 	ll ret = 1ll;
 	while (b) {
 	 	if (b&1) ret = (ret % MOD * a % MOD) % MOD;
 	 	a = (a % MOD * a % MOD) % MOD;
 	 	b >>= 1;
 	}
	return ret;
}

void solve(void) {
 	cin >> n >> m;
 	for (int i = 0; i < m; i++) {
 	 	cin >> str[i];
 	}
 	for (int i = 0; i < n; i++) {
 		int mask = 0;
 	 	for (int j = 0; j < m; j++) {
 			if (str[j][i] == 'H') {
 			 	mask |= (1 << j);
	 	 	}
 	 	}
 	 	cnt[mask]++;
 	}
 	fact[0] = 1ll;
 	inv_fact[0] = 1ll;
 	sum_inv_fact[0] = 1ll;
 	prob[0] = 1ll;
 	for (int i = 1; i <= n; i++) {
 	 	fact[i] = (fact[i-1] * (1ll * i)) % MOD;
 	 	inv_fact[i] = fast_power(fact[i], MOD-2);
 	 	sum_inv_fact[i] = (sum_inv_fact[i-1] + inv_fact[i]) % MOD;
 	}
 	for (int i = 1; i <= n; i++) {
 	 	prob[i] = fact[i];
 	 	prob[i] = (prob[i] % MOD * sum_inv_fact[i] % MOD) % MOD;
 	}
	for (int mask = 0; mask < (1 << m); mask++) {
		ll sum = 1ll;
		for (int i = 0; i < m; i++) {
			if (mask & (1 << i)) {
			 	sum = (sum % MOD + sum_dp[mask^(1<<i)][i] % MOD) % MOD;
			}
		}	
		dp[mask] = (sum * (prob[cnt[mask]]-1+MOD) % MOD) % MOD;
		sum_dp[mask][0] = dp[mask];
		for (int i = 1; i < m; i++) {
			sum_dp[mask][i] = (sum_dp[mask][i] % MOD + sum_dp[mask][i-1] % MOD) % MOD;
		 	if (mask & (1 << (i-1))) {
		 	 	sum_dp[mask][i] = (sum_dp[mask][i] % MOD + sum_dp[mask^(1<<(i-1))][i-1] % MOD) % MOD;
		 	}
		}
	}
	ll ret = 0ll;
	for (int mask = 0; mask < (1 << m); mask++) {
		ret = (ret % MOD + dp[mask] % MOD) % MOD;
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}



















