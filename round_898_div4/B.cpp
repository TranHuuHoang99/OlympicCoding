/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-13 11:10:45 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void solve(void) {
	cin >> n;
	vector<int> A(n,0);
	for (int i = 0; i < n; i++) cin >> A[i];
	int ret = 0;
	for (int i = 0; i < n; i++) {
	 	int val = A[i]+1;
	 	for (int j = 0; j < n; j++) {
	 	 	if (i == j) continue;
	 	 	val *= A[j];
	 	}
	 	ret = max(ret, val);
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

