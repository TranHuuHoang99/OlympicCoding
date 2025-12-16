/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-16 09:28:30 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

string str1;
string str2;
void solve(void) {
	cin >> str1 >> str2;
	string ret = "";
	int n = str1.size();
	for (int i = 0; i < n; i++) {
	 	if (str1[i] != str2[i]) {
	 	 	ret += '1';
	 	} else {
	 	 	ret += '0';
	 	}
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
 