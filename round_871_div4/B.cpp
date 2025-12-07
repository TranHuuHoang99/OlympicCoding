/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-07 20:12:14 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void solve(void) {
	cin >> n;
	int ret = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
	 	int val;
	 	cin >> val;
		if (val == 1) {
		 	cnt = 0;
		} else {
		    cnt++;
		}	
		ret = max(ret, cnt);
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

