/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-26 19:04:52 
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
     	data.assign(_row, vector<ll>(_col, 0ll));
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
int m, k;
ll add[3] = {1ll, 3ll, 3ll};

matrix fast_power(const matrix& a, const ll& b) {
 	if (b <= 1) return a;
 	matrix ret = fast_power(a, b>>1);
 	ret = ret * ret;
 	if (b&1) ret = ret * a;
	return ret;
}

void solve(void) {
	cin >> m >> k;
	matrix ret(1, k);
	ret.data[0][0] = 1ll;
	matrix base(k,k);
	for (int i = 0; i < k; i++) {
	 	for (int r = 0; r <= 2; r++) {
			base.data[(i-r+k)%k][i] = add[r]; 	 	
	 	}
	}
	base = fast_power(base, 1ll * m);
	ret = ret * base;
	cout << ret.data[0][0] - 1 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

