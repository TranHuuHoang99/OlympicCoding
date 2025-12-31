/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-09 20:09:12 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k;
void solve(void) {
	cin >> n >> k;
	vector<int> A(n,0);
	for (int i = 0; i < n; i++) cin >> A[i];
	sort(A.begin(), A.end());
	int ret = 1;
	int cnt = 0;
	for (int i = 1; i < n; i++) {
	 	if (A[i] - A[i-1] <= k) {
			cnt++;
			ret = max(ret, cnt+1);
	 	} else {
	 	    cnt = 0;
	 	}	
	}
	cout << n-ret << endl;
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

