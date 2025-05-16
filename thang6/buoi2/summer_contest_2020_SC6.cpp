#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 32;
const ll MOD = 1e9+7;
int n, p;
int A[N];
ll dp[N][N][N][N]; // i, odd white, even white, odd black
ll pow_two[N];
ll even[N];
ll odd[N];
ll fact[N];
ll inv[N];

ll fast_pow(ll a, ll b) {
	ll ret = 1ll;
	while (b) {
	 	if (b&1) ret = ret * a % MOD;
	 	a = a * a % MOD;
	 	b >>= 1;
	}
	return ret;
}

ll combination(int a, int b) {
	return (fact[a] % MOD * inv[b] % MOD * inv[a-b] % MOD) % MOD;
}

void init(void) {
	fact[0] = 1ll;
	inv[0] = 1ll;
    pow_two[0] = 1ll;
    for (int i = 1; i <= 30; i++) {
    	fact[i] = (fact[i-1] % MOD * 1ll * i % MOD) % MOD;
    	inv[i] = fast_pow(fact[i], MOD-2) % MOD;
     	pow_two[i] = pow_two[i-1] * 2ll % MOD; 
    }
    for (int i = 0; i <= 30; i++) {
		for (int j = 0; j <= i; j+=2) {
		 	even[i] += combination(i,j) % MOD;
		}
		for (int j = 1; j <= i; j+=2) {
		 	odd[i] += combination(i,j) % MOD;
		}
    }	
}

void solve(void) {
 	cin >> n >> p;
 	memset(A, 0, sizeof(A));
 	memset(dp, 0, sizeof(dp));
 	for (int i = 1; i <= n; i++) cin >> A[i];
 	dp[0][0][0][0] = 1ll;
 	for (int i = 0; i < n; i++) {
 	    for (int ow = 0; ow <= i; ow++) { // odd white
 	     	for (int ew = 0; ew + ow <= i; ew++) { // even white
 				for (int ob = 0; ob + ew + ow <= i; ob++) { // odd black
 				 	if (dp[i][ow][ew][ob] == 0ll) continue;
 				 	int eb = i - ow - ew - ob;
 				 	ll temp = dp[i][ow][ew][ob];
 				 	if (A[i+1] == 0) {
 				 	 	// odd white
 				 	 	dp[i+1][ow+1][ew][ob] += (pow_two[ow+ew+eb] % MOD * even[ob] % MOD * temp % MOD) % MOD;
 				 	 	// even white
 				 	 	dp[i+1][ow][ew+1][ob] += (pow_two[ow+ew+eb] % MOD * odd[ob] % MOD * temp % MOD) % MOD;
 				 	} else {
 				 	 	// odd black
 				 	 	dp[i+1][ow][ew][ob+1] += (pow_two[ew+ob+eb] % MOD * even[ow] % MOD * temp % MOD) % MOD;
 				 	 	// even black
 				 	 	dp[i+1][ow][ew][ob] += (pow_two[ew+ob+eb] % MOD * odd[ow] % MOD * temp % MOD) % MOD;
 				 	}
	     	 	}
 	     	}
 	    }
 	}
 	ll ret = 0ll;
 	for (int ow = 0; ow <= n; ow++) {
 	 	for (int ew = 0; ew + ow <= n; ew++) {
 	 	 	for (int ob = 0; ob + ew + ow <= n; ob++) {
 	 	 	 	if ((ow+ob) % 2 == p) {
 	 	 	 	 	ret = (ret + dp[n][ow][ew][ob]) % MOD;
 	 	 	 	}
 	 	 	}
 	 	}
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
	init();
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}













