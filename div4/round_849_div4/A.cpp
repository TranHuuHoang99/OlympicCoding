/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-01 11:18:08 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

string str = "codeforces";
set<char> save;
void solve(void) {
	char c;
	cin >> c;
	if (save.count(c)) {
	 	cout << "YES" << endl;
	} else {
	 	cout << "NO" << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (char c : str) save.insert(c);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}
 