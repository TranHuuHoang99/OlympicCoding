/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-26 12:27:44 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
string str;
void solve(void) {
	cin >> n;
	cin >> str;
	vector<int> ret;
	for (int i = 0; i < n; i++) {
	 	if (str[i] == '1') {
	 	 	ret.push_back(i+1);
	 	}
	}
	cout << ret.size() << endl;
	for (int r : ret) cout << r << ' ';
	cout << endl;
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

