/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-25 20:16:50 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9+7;
struct matrix {
  	int row, col;
  	vector<vector<ll>> data;
  	matrix(int _row, int _col) : row(_row), col(_col) {
  	 	data.assign(_row, vector<ll>(_col,0ll));
  	}
  	matrix operator *(const matrix& other) {
  	 	matrix ret(row, other.col);
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
const ll N = 110;
int n, m, k;
vector<int> adj[N];

matrix fast_power(const matrix& a, ll b) {
 	if (b <= 1) {
 	 	return a;
 	}
	matrix ret = fast_power(a, b>>1);
	ret = ret * ret;
	if (b&1) {
	 	ret = ret * a;
	}
	return ret;
}

void solve(void) {
 	cin >> n >> m >> k;
 	matrix base(1,n);
 	matrix filter(n,n);
 	for (int i = 1; i <= m; i++) {
 	 	int u, v;
 	 	cin >> u >> v;
		filter.data[u-1][v-1]++;		
 	}
 	base.data[0][0] = 1ll;
 	filter = fast_power(filter, k);
 	matrix ret = base;
 	ret = ret * filter;
 	cout << ret.data[0][n-1] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

