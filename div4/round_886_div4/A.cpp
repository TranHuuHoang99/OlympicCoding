/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-09 19:53:39 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(void) {
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b >= 10 || a + c >= 10 || b + c >= 10) {
	 	cout << "YES" << endl;
	 	return;
	}
	cout << "NO" << endl;
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

