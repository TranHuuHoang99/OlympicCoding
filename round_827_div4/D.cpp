/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-11-16 18:30:13 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(void) {
	int n;
	cin >> n;
	map<int,int> save;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		save[temp] = i;
	}
	int ret = -1;
	for (pair<int,int> p1 : save) {
	 	for (pair<int,int> p2 : save) {
			if (gcd(p1.first, p2.first) == 1) {
			 	ret = max(ret, p1.second + p2.second);
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

