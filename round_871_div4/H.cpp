/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-08 20:43:57 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;
int n, k;
void solve(void) {
	cin >> n >> k;
	vector<vector<int>> F(n+1, vector<int>(65, 0));
	for (int i = 1; i <= n; i++) {
	 	int val;
	 	cin >> val;
	 	F[i][val] = (F[i][val] % MOD + 1) % MOD;
	 	for (int mask = 0; mask <= 63; mask++) {
	 	 	F[i][mask] = (F[i][mask] % MOD + F[i-1][mask] % MOD) % MOD;
	 	 	F[i][mask&val] = (F[i][mask&val] % MOD + F[i-1][mask] % MOD) % MOD;
	 	}
	}
	int ret = 0;
	for (int mask = 0; mask <= 63; mask++) {
	 	if (__builtin_popcount(mask) == k) {
	 	 	ret = (ret % MOD + F[n][mask]% MOD) % MOD;
	 	}
	}
	cout << ret << endl;
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

