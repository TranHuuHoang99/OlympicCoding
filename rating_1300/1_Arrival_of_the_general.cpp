/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-16 09:07:36 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void solve(void) {
 	cin >> n;
 	map<int,int> save_min, save_max;
 	for (int i = 1; i <= n; i++) {
 	 	int val;
 	 	cin >> val;
 	 	save_min[val] = i;
 	 	if (save_max.find(val) == save_max.end()) {
 	 	 	save_max[val] = i;
 	 	}
 	}
 	int min_idx = save_min.begin()->second;
 	int max_idx = save_max.rbegin()->second;
 	if (max_idx < min_idx) {
 	 	int ret = max_idx - 1 + n - min_idx;
 	 	cout << ret << endl;
 	} else {
 	 	int ret = max_idx - 1 + n - min_idx - 1;
 	 	cout << ret << endl;
 	}
}   

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
 