/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-07 20:08:59 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

string str_sample = "codeforces";
string str;
void solve(void) {
	cin >> str;
	int ret = 0;
	for (int i = 0; i < 10; i++) {
	 	if (str[i] != str_sample[i]) ret++;
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

