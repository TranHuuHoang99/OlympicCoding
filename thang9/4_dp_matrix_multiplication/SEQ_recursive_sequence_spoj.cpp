/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-25 22:07:24 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9;
struct matrix {
  	int row, col;
  	vector<vector<ll>> data;
  	matrix(int _row, int _col) : row(_row), col(_col) {
  	 	data.assign(_row, vector<ll>(_col, 0ll));
  	}
  	matrix operator *(const matrix& other) {
  	 	matrix ret(row, col);
  	 	for (int i = 0; i < row; i++) {
  	 	 	for (int j = 0; j < other.col; j++) {
  	 	 	 	ll temp = 0ll;
  	 	 	 	for (int k = 0; k < col; k++) {
  	 	 	 	 	temp = (temp % MOD + (data[i][k] % MOD * other.data[k][j] % MOD) % MOD) % MOD;
  	 	 	 	}
  	 	 	 	ret.data[i][j] = temp;
  	 	 	}
  	 	}
  	 	return ret;
  	}
};
ll B[20], C[20];
int k;
int n;

matrix fast_power(const matrix& a, ll b) {
 	if (b <= 1) {
 	 	return a;
 	}
 	matrix ret = fast_power(a, b >> 1);
 	ret = ret * ret;
 	if (b&1) ret = ret * a;
 	return ret;
}

void solve(void) {
	cin >> k;
	memset(B, 0ll, sizeof(B));
	memset(C, 0ll, sizeof(C));
	for (int i = 0; i < k; i++) cin >> B[i];
	for (int i = 0; i < k; i++) cin >> C[i];
	cin >> n;
	if (n <= k) {
	 	cout << B[n-1] << endl;
	 	return;
	}
	matrix base(1, k);
	matrix filter(k,k);
	for (int i = 0; i < k; i++) base.data[0][i] = B[i];
	for (int i = 1; i < k; i++) {
		filter.data[i][i-1] = 1ll;	
 	}
 	for (int i = 0; i < k; i++) filter.data[i][k-1] = C[k - i- 1];
	filter = fast_power(filter, n-k);
	matrix ans = base;
	ans = ans * filter;
	cout << ans.data[0][k-1] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}

