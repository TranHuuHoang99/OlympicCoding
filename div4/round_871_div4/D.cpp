/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-07 20:19:14 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
bool dfs(int val) {
 	if (val == m) return true;
 	if (val < m || val % 3 != 0) return false;
 	int small = val / 3;
 	int big = 2 * small;
 	return dfs(small) || dfs(big);
}
void solve(void) {
	cin >> n >> m;
	if (dfs(n)) {
	 	cout << "YES" << endl;
	} else {
	 	cout << "NO" << endl;
	}
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

