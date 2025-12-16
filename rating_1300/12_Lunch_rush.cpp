/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-16 21:16:36 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4+10;
int n, k;
int F[N], T[N];
void solve(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
	 	cin >> F[i] >> T[i];
	}
	int ret = LLONG_MIN;
	for (int i = 1; i <= n; i++) {
	 	if (T[i] <= k) {
	 	 	ret = max(ret, F[i]);
	 	} else {
	 	 	ret = max(ret, F[i] + k - T[i]);
	 	}
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

