/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-25 13:46:54 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
int n;
int A[N];
vector<int> adj[N];

bool isAlexWin(int val) {
	for (int i = 1; i <= n; i++) adj[i].clear();
	set<pair<int,int>> s;
	for (int i = 1; i <= n; i++) {
	 	for (pair<int,int> temp : s) {
	 	 	if (A[i] - temp.first >= val) {
	 	 	 	adj[i].push_back(temp.second);
	 	 	 	adj[temp.second].push_back(i);
	 	 	}
	 	}
	 	s.insert({A[i], i});
	 	if (s.size() > 3) {
			s.erase(prev(s.end()));
	 	}
 	}
 	int cnt = 0;
 	for (int i = 1; i <= n; i++) {
 	 	if (adj[i].size() >= 2) cnt++;
 	}
 	for (int i = 1; i <= n; i++) {
 	 	int cnt2 = adj[i].size() >= 2;
 	 	for (int v : adj[i]) {
 	 		if (adj[v].size() == 2) {
 	 		 	cnt2++;
 	 		}
 	 	}
 	 	if (cnt == cnt2) return false;
 	}
 	return true;
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	int left = -1000000005;
	int right = 1000000005;
	int ret = -1;
	while (left <= right) {
	 	int mid = (left+right)>>1;
	 	if (isAlexWin(mid)) {
	 		ret = mid;
	 	 	left = mid + 1;
	 	} else {
	 	 	right = mid - 1;
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


