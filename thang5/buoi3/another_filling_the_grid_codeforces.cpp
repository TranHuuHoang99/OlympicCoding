/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 18.04.2025 19:33:12
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 300;
const ll MOD = 1e9+7;
int n, k;
ll dp[N][N];
ll powerK[N];
ll powerK_1[N];
ll comb[N][N];
ll fact[N];

void build_fact(void) {
 	fact[0] = 1ll;
 	for (int i = 1; i <= 250; i++) {
 	 	fact[i] = fact[i-1] * 1ll * i % MOD;
 	 	fact[i] %= MOD;
 	}
}

ll fast_pow(ll a, ll b) {
 	ll ret = 1ll;
 	while (b) {
 	    if (b&1) ret = ret * a % MOD;
 	    a = a * a % MOD;
 	    b >>= 1;
 	}	
 	return ret;
}

ll combination(ll a, ll b) {
	ll ret = (fact[a] % MOD * fast_pow(fact[b], MOD-2) % MOD * fast_pow(fact[a-b], MOD-2) % MOD) % MOD;
	ret %= MOD;
	return ret;
}

void solve(void) {
	cin >> n >> k;
	powerK[0] = powerK_1[0] = 1ll;
	for (int i = 1; i <= n; i++) {
	 	powerK[i] = (powerK[i-1] % MOD * k % MOD) % MOD;
	 	powerK_1[i] = (powerK_1[i-1] % MOD * 1ll * (k-1) % MOD) % MOD;
	}
	// calculate combination
	for (int i = 1; i <= 250; i++) {
	 	for (int j = 1; j <= 250; j++) {
	 	 	comb[i][j] = combination(1ll * j, 1ll * i);
	 	}
	}
	// goi dp[i][j] la so cach viet cac so vao moi o tu 1 -> k
	// voi i la so hang 
	// voi j la nhung cot da duoc viet cac so
	dp[0][0] = 1ll;
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j <= n; j++) {
			// xet truong hop hang thu i+1 khong muon viet so 1 vao nhung o n - j 
			// n-j o nay se khong o nao chua so 1
			// ta co j la so cot trong hang i+1 da duoc viet so, ta phai bao dam j o nay it nhat moi o phai co 1 o la so 1
			// ta co k^j la so cach viet vao j o, vi se co truong hop tat ca cac o j khong o nao chua so 1 ca
			// nen ta phai loai bo nhung truong hop nay ra
			// truong hop k co o nao chua so 1 la (k-1) ^ j
			dp[i+1][j] += (dp[i][j] % MOD * (powerK[j] - powerK_1[j] + MOD) % MOD * powerK_1[n-j] % MOD) % MOD;
			dp[i+1][j] %= MOD;
			// ta xet truong hop se them x o chua so 1 vao nhung o n-j => se co j+x o la nhung o da viet so
			// va ta se co (n-j) C x so cach chon o x
			// vi hang nay chac chang se co nhung o chua so 1 nen ta se lay tat ca cac truong hop tu 1->k cua j o
			for (int x = 1; x + j <= n; x++) {
				dp[i+1][x+j] += (dp[i][j] % MOD * powerK[j] % MOD * comb[x][n-j] % MOD * powerK_1[n-j-x] % MOD) % MOD;
				dp[i+1][x+j] %= MOD;
			}
	    }
	}
	cout << dp[n][n] << endl;	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	build_fact();
	
	solve();

	return 0;
}
