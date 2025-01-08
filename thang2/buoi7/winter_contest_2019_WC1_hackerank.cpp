/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 07.01.2025 23:38:30
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+1;
const ll MOD = 68718952446ll;
ll A[N];
ll prefix[N];
ll suffix[N];
int n;

ll mul(ll a, ll b) {
	// b = d * 100000 + r
	// d = b / 100000
	// r = b % 100000
	// a * b = a * (d * 100000 + r)
	// a * (d * 100000 + r) = [(a*d) * 100000 + a * r] % MOD
 	if (b == 0) return 0ll;
 	ll temp = mul(a, b/100000);
 	temp = (temp * 1ll * 100000ll) % MOD;
 	temp = (temp%MOD + (1ll * (b%100000) * a)%MOD) % MOD;
 	return temp;
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	prefix[0] = 1ll;
	suffix[n+1] = 1ll;
	for (int i = 1; i <= n; i++) {
	 	prefix[i] = (prefix[i-1] * A[i]) % MOD;
	}
	for (int i = n; i >= 1; i--) {
	 	suffix[i] = (suffix[i+1] * A[i]) % MOD;
	}
	for (int i = 1; i <= n; i++) {
	 	ll ret = mul(prefix[i-1], suffix[i+1]);
	 	cout << ret << ' ';
	}
	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("WC1.INP", "r", stdin);
	freopen("WC1.OUT", "w", stdout);
#endif // HOANGPRODN_DEBUG

	int t;
	cin >> t;
	while (t--) {
	 	solve();
	}

	return 0;
}
