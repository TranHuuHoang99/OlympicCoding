/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-02 21:37:55 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, q;
int A[N];
int prefix[N];
void solve(void) {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) {
	 	prefix[i] = prefix[i-1] + A[i];
	}
	for (int i = 1; i <= q; i++) {
	 	int left, right, k;
	 	cin >> left >> right >> k;
	 	int sum = prefix[n] - (prefix[right] - prefix[left-1]);
	 	sum += (right-left+1)*k;
	 	if (sum % 2 == 0) {
	 	 	cout << "NO" << endl;
	 	} else {
	 	 	cout << "YES" << endl;
	 	}
	}
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

