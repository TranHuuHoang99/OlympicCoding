/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-02 20:46:10 
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
	vector<int> type(26, -1);
	string ret = str;
	for (int i = 0; i < n; i++) {
		int idx = int(str[i]-'a');
		if (type[idx] != -1) {
		 	ret[i] = char('0'+type[idx]);
		 	continue;
		}
		if (i-1 >= 0) {
			if (ret[i-1] == '0') {
			 	ret[i] = '1';
		 	} else {
		 	 	ret[i] = '0';
		 	}
		} else {
		 	ret[i] = '0';
		}
		type[idx] = int(ret[i]-'0');
	}
	//cout << ret << endl;
	for (int i = 0; i < n-1; i++) {
	 	if (ret[i] == ret[i+1]) {
	 	 	cout << "NO" << endl;
	 	 	return;
	 	}
	}
	cout << "YES" << endl;
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

