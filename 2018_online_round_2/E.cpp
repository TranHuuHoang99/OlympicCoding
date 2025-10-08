/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-08 20:03:29 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9+7;
struct Matrix {
  	int row, col;
  	vector<vector<ll>> data;
  	Matrix(int _row, int _col) {
  	 	row = _row;
  	 	col = _col;
  	 	data.assign(row, vector<ll>(col, 0ll));
  	}
  	Matrix operator *(const Matrix& other) {
  	 	Matrix ret(row, other.col);
  	 	for (int i = 0; i < row; i++) {
  	 	 	for (int j = 0; j < other.col; j++) {
  	 	 		ll sum = 0ll;
  	 	 	 	for (int k = 0; k < other.row; k++) {
  	 	 	 		sum = (sum % MOD + (data[i][k] % MOD * other.data[k][j] % MOD) % MOD) % MOD;
  	 	 	 	}
  	 	 	 	ret.data[i][j] = sum;
  	 	 	}
  	 	}
  	 	return ret;
  	}
};
ll A, B;
Matrix init_m(1,10);
Matrix base_m(10, 10);
int base[10][10] = {
  	{0, 1, 0, 5, 0, 0, 21, 0, 0, 26},
  	{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
  	{0, 0, 0, -125, 0, 0, -21, 0, 0, -146},
  	{3, 0, 0, 5, 1, 0, 21, 0, 0, 26},
  	{9, 0, 0, 0, 0, 1, 0, 0, 0, 0},
  	{0, 0, 0, 0, 0, 0, -21, 0, 0, -21},                                             
  	{3, 0, 0, 5, 0, 0, 21, 1, 0, 26},
  	{9, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  	{0, 0, 0, -125, 0, 0, -20, 0, 0, -145},
  	{0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
};
int init[1][10] = {
	{2262, 78, 0, 3645, 130, 5, 15813, 546, 21, 20160}
};

Matrix fast_power(const Matrix& a, const ll& b) {
 	if (b <= 1) return a;
 	Matrix ret = fast_power(a, b>>1);
 	ret = ret * ret;
 	if (b&1) ret = ret * a;
 	return ret;
}

void solve(void) {
	cin >> A >> B;
	for (int i = 0; i < 1; i++) {
	 	for (int j = 0; j < 10; j++) {
	 	 	init_m.data[i][j] = init[i][j];
	 	}
	}
	for (int i = 0; i < 10; i++) {
	 	for (int j = 0; j < 10; j++) {
	 	 	base_m.data[i][j] = base[i][j];
	 	}
	}
	Matrix right_base = base_m;
	right_base = fast_power(right_base, B);
	Matrix right_init = init_m;
	right_init = right_init * right_base;
	ll right_val = (right_init.data[0][3] % MOD + right_init.data[0][6] % MOD) % MOD;
	cout << right_val << endl;
	cout << right_val - 20160 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}











































