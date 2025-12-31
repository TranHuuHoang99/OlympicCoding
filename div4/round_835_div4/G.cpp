/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-01 09:26:18 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
int n, s, e;
vector<pair<int,int>> adj[N];
set<int> save;
void dfs1(int u, int father, int val) {
 	if (u == e) return;
 	save.insert(val);
 	for (pair<int,int> next : adj[u]) {
 	 	auto [v, weight] = next;
 	 	if (v == father) continue;
 	 	dfs1(v, u, weight ^ val);
 	}
}
bool dfs2(int u, int father, int val) {
 	if (u != e && save.count(val)) return true;
 	for (pair<int,int> next : adj[u]) {
 	 	auto [v, weight] = next;
 	 	if (v == father) continue;
 	 	if (dfs2(v, u, val ^ weight)) return true;
 	}
 	return false;
}
void solve(void) {
 	cin >> n >> s >> e;
 	for (int i = 1; i <= n; i++) adj[i].clear();
 	save.clear();
 	for (int i = 1; i <= n-1; i++) {
 	 	int u, v, weight;
 	 	cin >> u >> v >> weight;
 	 	adj[u].push_back({v,weight});
 	 	adj[v].push_back({u, weight});
 	}
 	dfs1(s, -1, 0);
 	if (dfs2(e, -1, 0)) {
 	 	cout << "YES" << endl;
 	} else {
 	 	cout << "NO" << endl;
 	}
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
 