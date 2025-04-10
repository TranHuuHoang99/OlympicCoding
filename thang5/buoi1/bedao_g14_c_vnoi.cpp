/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 09.04.2025 22:31:16
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e6+10;
const ll MOD = 1e9+7;
ll a0,a1,b0,b1;
ll fact[N], inv[N];

ll fast_pow(ll a, ll b) {
 	ll ret = 1;
 	while (b) {
 	 	if (b&1) ret = ret * a % MOD;
 	 	a = a * a % MOD;
 	 	b >>= 1;
 	}
 	return ret;
}

void init(void) {
 	fact[0] = inv[0] = 1ll;
 	for (int i = 1; i <= 2e6; i++) {
		fact[i] = fact[i-1] * 1ll * i % MOD;
		inv[i] = fast_pow(fact[i], MOD-2); 	 	
 	}
}

ll combination(ll n, ll k) {
	ll ret = (fact[n] % MOD * inv[k] % MOD * inv[n-k] % MOD) % MOD;
 	return ret;
}

void solve(void) {
	init();
	cin >> a0 >> a1 >> b0 >> b1;
	ll ret = 0ll;
	for (ll gr = 1ll; gr * b0 <= a0; gr++) {
	 	ll people_0 = gr;
	 	ll people_1 = gr;
	 	if (people_1 * b1 <= a1) {
	 	 	ll candies_0 = a0 - people_0 * b0;
	 	 	ll candies_1 = a1 - people_1 * b1;
	 	 	ll choice_0 = combination(people_0 + candies_0, people_0);
	 	 	ll choice_1 = combination(people_1 + candies_1, people_1);
	 	 	ret += (2ll * choice_0 % MOD * choice_1 % MOD) % MOD;
	 	 	ret %= MOD;
	 	}
	 	people_1 = gr + 1;
	 	if (people_1 * b1 <= a1) {
	 	 	ll candies_0 = a0 - people_0 * b0;
	 	 	ll candies_1 = a1 - people_1 * b1;
	 	 	ll choice_0 = combination(people_0 + candies_0, people_0);
	 	 	ll choice_1 = combination(people_1 + candies_1, people_1);
	 	 	ret += (choice_0 % MOD * choice_1 % MOD) % MOD;
	 	 	ret %= MOD;
	 	}
	 	people_1 = gr - 1;
	 	if (people_1 != 0 && people_1 * b1 <= a1) {
	 	 	ll candies_0 = a0 - people_0 * b0;
	 	 	ll candies_1 = a1 - people_1 * b1;
	 	 	ll choice_0 = combination(people_0 + candies_0, people_0);
	 	 	ll choice_1 = combination(people_1 + candies_1, people_1);
	 	 	ret += (choice_0 % MOD * choice_1 % MOD) % MOD;
	 	 	ret %= MOD;
	 	}
	}
	cout << (ret % MOD) << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
