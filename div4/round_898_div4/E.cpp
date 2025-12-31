/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-12 15:10:27 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, x;
int A[N];
void solve(void) {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> A[i];
	int left = 1;
	int right = 2e9+10;
	int ret = -1;
	while (left <= right) {
	 	int mid = (left+right)>>1;
		int cnt = 0;
		for (int i = 1; i <= n; i++) cnt += max(0ll, mid - A[i]);
		if (cnt <= x) {
		 	ret = mid;
		 	left = mid + 1;
		} else {
		 	right = mid - 1;
		}
	}
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
 