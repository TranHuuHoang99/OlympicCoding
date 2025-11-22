/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-11-17 21:24:19 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int cal(vector<int> save) {
 	if (save.empty()) return 0;
 	int ret = 0;
 	int pos = (int)save.size()/2;
 	for (int i = 0; i < save.size(); i++) {
 	 	ret += abs(save[pos]-save[i]) - abs(pos-i);
 	}
 	return ret;
}
void solve(void) {
	cin >> n;
	vector<int> pos_a, pos_b;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == 'a') {
		 	pos_a.push_back(i);
		} else {
		 	pos_b.push_back(i);
		}
	}
	cout << min(cal(pos_a), cal(pos_b)) << endl;
}

int32_t main(void) {
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

