/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 11.04.2025 21:16:13
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1e9+7;
const ll N = 1e5+10;
int n;
ll x, k;

ll fast_pow(ll a, ll b) {
 	ll ret = 1;
 	while (b) {
 	 	if (b&1) ret = ret * a % MOD;
 	 	a = a * a % MOD;
 	 	b >>= 1;
 	}
 	return ret;
}

void solve(void) {
 	cin >> n;
 	ll numb = 1ll, sum = 1ll, product = 1ll, cnt = 1ll;
 	for (int i = 1; i <= n; i++) {
 	 	cin >> x >> k;
 	 	numb = numb * (k+1ll) % MOD;
 	 	sum = (sum % MOD * (fast_pow(x, k+1ll) - 1ll) % MOD * fast_pow(x - 1, MOD - 2) % MOD) % MOD;
 	 	product = (fast_pow(product, k+1) % MOD * fast_pow(fast_pow(x, (k * (k+1ll) / 2ll)), cnt) % MOD) % MOD;
 	 	cnt = cnt * (k+1ll) % (MOD-1);
 	}
 	cout << numb << ' ' << sum << ' ' << product << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
