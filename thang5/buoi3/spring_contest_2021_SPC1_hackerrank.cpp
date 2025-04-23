/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 17.04.2025 21:17:20
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+10;
const ll MOD = 1e9+7;
ll A[N];
ll dp[N][N];
int n, k;

ll fast_pow(ll a, ll b) {
 	ll ret = 1ll;
 	while (b) {
 	 	if (b&1) ret = ret * a % MOD;
 	 	a = a * a % MOD;
 	 	b >>= 1;
 	}
 	return ret;
}

void solve(void) {
	cin >> n >> k;
	ll totalChildren = 0ll;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
	 	totalChildren += 1ll * A[i];
	}
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= k; j++) {
	 	 	dp[i][j] = 0ll;
	 	}
	}
	dp[0][0] = 1ll;
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j <= k; j++) {
	 	 	// xet truong hop ba me i+1 ngoi vao 1 cai ban moi vay thi ba me i+1 se co k-j su lua chon
	 	 	if (j+1 <= k) {
	 	 	 	dp[i+1][j+1] += (1ll * (k-j) % MOD * (dp[i][j]) % MOD) % MOD;
	 		}
	 		// xet truong hop ba me i+1 ngoi vao ban ma da co cac ba me khac ngoi thi ba me i+1 co j su lua chon
	 		dp[i+1][j] += (1ll * j % MOD * dp[i][j] % MOD) % MOD;
	 	}
	}
	ll ret = 0ll;
	for (int i = 1; i <= k; i++) {
		// xet truong xep cac ba me ngoi vao truoc, va con du ra 1 so ban trong la k-i (ban trong)
		ll temp = 1ll * (k-i+1);
		// nhung dua tre co the ngoi vao ban k co ba me nao ca, hoac ngoi cung ban co me cua chung nen ta co
		// so cach sap xep chp nhung dua tre la (k-i) ^ totalChildren
		// ta nhan so cach sap xep cac dua tre va so cach sap xep cac ba me ta dc dap an bai toan
		ret += (fast_pow(temp, totalChildren) % MOD * dp[n][i] % MOD) % MOD;
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
