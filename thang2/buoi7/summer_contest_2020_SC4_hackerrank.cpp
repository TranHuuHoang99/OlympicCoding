/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 08.01.2025 15:22:08
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll x, n, m;

ll fastpow(ll a, ll b, ll MOD) {
 	ll ret = 1;
 	while (b) {
 	 	if (b&1) ret = ret * a % MOD;
 	 	a = a*a % MOD;
 	 	b >>= 1;
	}
	return ret;
}

ll P(ll a, ll b, ll MOD) {
	if (b == 0) return 1ll;
	if (b%2 == 1) {
	 	ll ret = P(a,b/2,MOD);
	 	ret = ((ret%MOD) * (1ll+fastpow(a, b/2+1, MOD))%MOD) % MOD;
	 	return ret;
	}
	return ((P(a,b-1,MOD)%MOD) + (fastpow(a,b,MOD)%MOD))%MOD;
}

void solve(void) {
	cin >> x >> n >> m;
	if (x == 1) {
	 	cout << (n%m) << endl;
	 	return;
	}
	cout << (P(x,n,m) % m) << endl;
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
