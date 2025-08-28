/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-19 20:48:36 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9+7;
struct matrix {
  	int row, col;
  	vector<vector<ll>> data;
  	matrix(int _row, int _col)
  	{
  		row = _row;
  		col = _col;
  	 	data.assign(_row, vector<ll>(_col,0ll));
  	}
  	matrix operator *(const matrix& other) {
  	 	matrix ret(row, other.col);
  	 	for (int i = 0; i < row; i++) {
  	 	 	for (int j = 0; j < other.col; j++) {
  	 	 	 	ll sum = 0ll;
  	 	 	 	for (int k = 0; k < other.row; k++) {
  	 	 	 		sum = (sum % MOD + (other.data[k][j] % MOD * data[i][k] % MOD) % MOD) % MOD;	
  	 	 	   	}
  	 	 	   	ret.data[i][j] = sum;
  	 	 	}
  	 	}
  	 	return ret;
  	}
};
ll n;
matrix base(2,2), init(1,2);

matrix fast_power(matrix a, ll b) {
 	matrix ret(a.row,a.col);
 	ret.data[0][0] = ret.data[1][1] = 1ll;
 	ret.data[0][1] = ret.data[1][0] = 0ll;
 	while (b) {
 	 	if (b&1) ret = ret * a;
 	 	a = a * a;
 	 	b >>= 1;
 	}
 	return ret;
}

void solve(void) {
 	cin >> n;
 	if (n <= 1) {
 	 	cout << n << endl;
 	 	return;
 	}
 	init.data[0][0] = 0ll; // dp[0] = 0
 	init.data[0][1] = 1ll; // dp[1] = 1
 	for (int i = 0; i <= 1; i++) {
 	 	for (int j = 0; j <= 1; j++) {
 	 	 	if (i == 0 && j == 0) {
 	 	 	 	base.data[i][j] = 0ll;
 	 	 	} else {
 	 	 	 	base.data[i][j] = 1ll;
 	 	 	}
 	 	}
 	}
 	base = fast_power(base, n-1);
 	matrix ans = init;
 	ans = ans * base;
 	cout << ans.data[0][1] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

