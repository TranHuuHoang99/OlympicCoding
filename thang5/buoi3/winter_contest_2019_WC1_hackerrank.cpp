/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 15.04.2025 20:59:33
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+10;
const ll MOD = 1e9+7;
int n;
ll dp[N];
ll fact[N];

ll fast_pow(ll a, ll b) {
    ll ret = 1ll;
    while (b) {
        if (b&1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }	
	return ret;
}	

void build(void) {
 	fact[0] = 1;
 	for (int i = 1; i <= 1e3; i++) {
 	 	fact[i] = fact[i-1] % MOD * 1ll * i % MOD;
 	 	fact[i] %= MOD;
 	}
}

ll comb(int a, int b) {
 	ll ret = fact[a] % MOD * fast_pow(fact[b], MOD-2) % MOD * fast_pow(fact[a-b], MOD-2) % MOD;
 	ret %= MOD;
 	return ret;
}

void solve(void) {
	cin >> n;
	for (int i = 0; i <= n; i++) dp[i] = 0ll;
	dp[0] = 1ll;
	for (int i = 0; i <= n; i++) {
	    for (int j = 1; j <= i; j++) {
			dp[i] += dp[i-j] % MOD * comb(i-1, j-1) % MOD; // vi so cach chon co the trung nhau nen ta phai de so i lon nhat
														   // ra sau cung, nen tap hop chi con lai i-1 va j-1 cach chon
			dp[i] %= MOD;  	     	
	    }
	}	
	cout << (dp[n] % MOD) << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	build();

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}
