/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-16 21:44:30 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
           
const int N = 1e3+10;
int A[N];
void solve(void) {
 	int n, m;
 	cin >> n >> m;
 	for (int i = 1; i <= n; i++) cin >> A[i];
 	int ret = 0;
 	for (int i = 1; i <= m; i++) {
 		int u, v;
 		cin >> u >> v;
 		ret += min(A[u], A[v]);
	}
	cout << ret << endl;
}

signed main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
 