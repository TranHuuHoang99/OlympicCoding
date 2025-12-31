/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-13 11:07:58 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

string sample_str = "abc";
string str;
void solve(void) {
	cin >> str;
	int ret = 0;
	for (int i = 0; i < 3; i++) {
	 	if (str[i] != sample_str[i]) ret++;
	}
	if (ret <= 2) {
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

