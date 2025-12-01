/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-11-23 22:01:57 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
string str;
void solve(void) {
	cin >> n >> str;
	int ret = 0;
	for (char c : str) {
	 	ret = max(ret, int(c-'a'));
	}
	cout << ret + 1 << endl;
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

