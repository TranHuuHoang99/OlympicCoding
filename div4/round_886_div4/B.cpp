/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-09 20:01:21 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(void) {
	int n;
	cin >> n;
	int ret = -1;
	int max_val = -1;
	for (int i = 1; i <= n; i++) {
	 	int a, b;
	 	cin >> a >> b;
	 	if (a <= 10) {
	 	 	if (b > max_val) {
				max_val = b;
				ret = i;
	 	 	}
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

