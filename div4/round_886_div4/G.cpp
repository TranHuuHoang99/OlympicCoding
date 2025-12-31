/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-10 21:41:33 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
void solve(void) {
	cin >> n;
	map<int,int> hor, ver, diag1, diag2;
	for (int i = 1; i <= n; i++) {
	 	int x, y;
	 	cin >> x >> y;
		ver[x]++;
		hor[y]++;
		diag1[x-y]++;
		diag2[x+y]++;
	}
	int ret = 0;
	for (pair<int,int> val : hor) ret += val.second * (val.second-1);
	for (pair<int,int> val : ver) ret += val.second * (val.second-1);
	for (pair<int,int> val : diag1) ret += val.second * (val.second-1);
	for (pair<int,int> val : diag2) ret += val.second * (val.second-1);
	cout << ret << endl;
}

signed main(void) {
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

