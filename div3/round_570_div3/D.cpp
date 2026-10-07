/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2026-10-15 16:57:28 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
void solve(void) {
	cin >> n;
	map<int,int> cnt;
	set<int> s_type;
	for (int i = 1; i <= n; i++) {
	 	int val;
	 	cin >> val;
	 	cnt[val] += 1;
	 	s_type.insert(val);
	}
	vector<int> numb_arr;
	for (int type : s_type) {
	 	numb_arr.push_back(cnt[type]);
	}
	sort(numb_arr.begin(), numb_arr.end(), greater<int>());
	int cur_val = numb_arr[0];
	int ret = cur_val;
	cur_val = max(cur_val - 1, 0ll);
	for (int i = 1; i < numb_arr.size(); i++) {
	 	if (numb_arr[i] >= cur_val) {
	 	 	ret += cur_val;
	 	 	cur_val = max(cur_val - 1, 0ll);
	 	} else {
	 	 	ret += numb_arr[i];
	 	 	cur_val = max(numb_arr[i] - 1, 0ll);
	 	}
	}
	cout << ret << '\n';
}

signed main(void) {
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


