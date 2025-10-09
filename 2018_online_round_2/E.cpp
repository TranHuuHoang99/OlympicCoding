/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-08 10:37:57 
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
  	 	 	for (int j = 0; j < col; j++) {
  	 	 		ll sum = 0ll;
  	 	 	 	for (int k = 0; k < col; k++) {
					sum = (sum % MOD + (data[i][k] % MOD * other.data[k][j] % MOD) % MOD) % MOD;
  	 	 	 	}
  	 	 	 	ret.data[i][j] = sum;
  	 	 	}
  	 	}
  	 	return ret;
  	}
};
vector<vector<ll>> init_matrix = {
  	{2262, 78, 0, 3645, 130, 5, 15813, 546, 21, 20160}
};
vector<vector<ll>> base_matrix = {
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
ll A, B;
Matrix init(1, 10), base(10, 10);

Matrix fast_power(const Matrix& a, const ll& b) {
 	if (b <= 1) return a;
 	Matrix ret = fast_power(a, b>>1);
 	ret = ret * ret;
 	if (b&1) ret = ret * a;
 	return ret;
}

ll getSum(const ll& val) {
	if (val == 0) {
	 	return 0;
	} else if (val == 1) {
	 	return 26;
	} else if (val == 2) {
	 	return 702;
	} else if (val == 3) {
	 	return 20160;
	}
	Matrix filter = base;
	filter = fast_power(filter, val-3);
	Matrix input = init;
	input = input * filter;
	ll ret = input.data[0][9] % MOD;
	if (ret < 0ll) ret += MOD;
	return ret;
}

void solve(void) {
 	cin >> A >> B;
 	for (int i = 0; i < 1; i++) {
 	 	for (int j = 0; j < 10; j++) {
			init.data[i][j] = init_matrix[i][j];
 	 	}
 	}
 	for (int i = 0; i < 10; i++) {
 	 	for (int j = 0; j < 10; j++) {
 	 	 	base.data[i][j] = base_matrix[i][j];
 	 	}
 	}
 	ll ret = (getSum(B) - getSum(A-1)) % MOD;
 	if (ret < 0ll) ret += MOD;
 	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


















