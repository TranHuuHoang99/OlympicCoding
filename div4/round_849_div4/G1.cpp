/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-01 16:59:14 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n, c;
void solve(void) {
	cin >> n >> c;
	vector<int> save;
	for (int i = 1; i <= n; i++) {
	 	int val;
	 	cin >> val;
	 	save.push_back(i+val);
	}
	sort(save.begin(), save.end());
	int ret = 0;
	for (int i = 0; i < save.size(); i++) {
	 	if (c >= save[i]) {
	 	 	ret++;
	 	 	c -= save[i];
	 	} else {
	 	 	break;
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
 