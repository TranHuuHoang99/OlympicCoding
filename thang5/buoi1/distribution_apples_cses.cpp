/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 08.04.2025 21:15:10
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1e9+7;
const ll N = 2e6+10;
ll fact[N];
ll inv[N];

ll fast_pow(ll a, ll expo) {
 	ll ret = 1;
 	while (expo) {
 	 	if (expo&1) ret = ret * a % MOD;
 	 	a = a * a % MOD;
 	 	expo >>= 1;
 	}
 	return ret;
}

void calFact(void) {
 	fact[0] = 1;
 	for (int i = 1; i <= 2e6; i++) {
 	 	fact[i] = ((fact[i-1] % MOD) * (1ll * i % MOD)) % MOD;
 	}
}

void solve(void) {
	calFact();
	int a, b;
	cin >> a >> b;
	int n = a + b - 1;
	int k = a - 1;
	ll factn = fact[n];
	ll factk = fact[k];
	ll fact_n_minus_k = fact[n-k];
	ll temp = ((factk % MOD) * (fact_n_minus_k%MOD)) % MOD;
	ll ret = ((factn % MOD) * (fast_pow(temp,MOD-2) % MOD)) % MOD;
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
