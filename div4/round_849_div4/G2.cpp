/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-02 08:39:08 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, c;
bool cmp(pair<int,int> a, pair<int,int> b) {
 	return a.first < b.first;
}
void solve(void) {
 	cin >> n >> c;
	vector<pair<int,int>> save;
	for (int i = 0; i < n; i++) {
	 	int val;
	 	cin >> val;
		save.push_back({val+min(i+1,n-i), val+i+1});
	}
	sort(save.begin(), save.end(), cmp);
	vector<int> prefix;
	prefix.push_back(0);
	for (int i = 0; i < n; i++) {
	 	prefix.push_back(prefix.back()+save[i].first);
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
	 	int init_val = c - save[i].second;
	 	int left = 0;
	 	int right = n;
	 	while (left <= right) {
	 	 	int mid = (left+right)>>1;
	 	 	int cost = prefix[mid];
	 	 	int pos = mid+1;
	 	 	if (mid > i) {
	 	 	 	cost -= save[i].first;
	 	 	 	pos--;
	 	 	}
	 	 	if (init_val >= cost) {
	 	 	 	ret = max(ret, pos);
	 	 	 	left = mid + 1;
	 	 	} else {
	 	 	 	right = mid - 1;
	 	 	}
	 	}
	}
	cout << ret << endl;
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
 