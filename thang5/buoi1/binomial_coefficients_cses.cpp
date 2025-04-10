/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 08.04.2025 20:49:28
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1e9+7;
const ll N = 1e6+10;
ll fact[N];
ll a, b;

void count_fact(void) {
 	fact[0] = 1;
 	for (int i = 1; i <= 1e6; i++) {
 	 	fact[i] = ((fact[i-1]%MOD) * (1ll*i%MOD)) % MOD;
 	}
}

ll power(ll x, ll y) {
 	ll ret = 1;
 	while (y) {
 	 	if (y&1) ret = ret * x % MOD;
 	 	x = x * x % MOD;
 	 	y >>= 1;
 	}
 	return ret;
}

void solve(void) {
	cin >> a >> b;
	ll tempA = fact[a];
	ll tempB = fact[b];
	ll tempC = fact[a-b];
	ll tempD = ((tempB % MOD) * (tempC % MOD)) % MOD;
	ll ret = ((tempA % MOD) * (power(tempD, MOD-2) % MOD)) % MOD;
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

	count_fact();

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}
