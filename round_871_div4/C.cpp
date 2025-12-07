/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-07 20:14:52 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void solve(void) {
	cin >> n;
	int ret = INT32_MAX;
	int left = 4e5+10;
	int right = 4e5+10;
	for (int i = 1; i <= n; i++) {
	 	int val;
	 	string str;
	 	cin >> val >> str;
	 	if (str[0] == '1' && str[1] == '1') {
	 	 	ret = min(ret, val);
	 	} else {
	 	 	if (str[0] == '1') {
	 	 	 	left = min(left, val);
	 	 	}
	 	 	if (str[1] == '1') {
	 	 	 	right = min(right, val);
	 	 	}
	 	 	ret = min(ret, left+right);
	 	}
	}
	if (ret <= 4e5) {
	 	cout << ret << endl;
	} else {
	 	cout << -1 << endl;
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

