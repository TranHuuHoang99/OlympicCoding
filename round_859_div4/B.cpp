/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-02 20:31:12 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void solve(void) {
	cin >> n;
	int even = 0;
	int odd = 0;
	for (int i = 1; i <= n; i++) {
	 	int val;
	 	cin >> val;
	 	if (val % 2 == 0) {
	 	 	even += val;
	 	} else {
	 	 	odd += val;
	 	}
	}
	if (even > odd) {
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

