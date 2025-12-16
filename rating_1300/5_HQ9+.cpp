/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-16 10:29:24 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

set<char> save;
void solve(void) {
	save.insert('H');
	save.insert('Q');
	save.insert('9');
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
	 	if (save.find(str[i]) != save.end()) {
	 	 	cout << "YES" << endl;
	 	 	return;
	 	}
	}
	cout << "NO" << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
 