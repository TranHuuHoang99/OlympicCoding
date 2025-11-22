/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-11-17 20:53:19 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(void) {
	int n;
	cin >> n;
	int minus_one = 0;
	int zero = 0;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		if (temp == -1) minus_one++;
		if (temp == 0) zero++;
	}
	cout << (minus_one%2) * 2 + zero << endl; 
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

