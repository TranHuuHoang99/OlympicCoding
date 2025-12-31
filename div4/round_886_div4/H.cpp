/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-10 22:31:02 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, m;
vector<pair<int,int>> adj[N];
bool visited[N];
int dist[N];
void dfs(int u) {
 	visited[u] = true;
 	for (pair<int,int> node : adj[u]) {
 		int v = node.first;
 		int range = node.second;
 		if (visited[v]) continue;
 		dist[v] = dist[u] + range;
 		dfs(v);
 	}
}
void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
	 	adj[i].clear();
	 	dist[i] = 0;
	 	visited[i] = false;
	}
	vector<array<int,3>> save;
	for (int i = 1; i <= m; i++) {
	 	int u, v, val;
	 	cin >> u >> v >> val;
	 	adj[u].push_back({v,val});
	 	adj[v].push_back({u,-val});
	 	save.push_back({u,v,val});
	}
	for (int i = 1; i <= n; i++) {
	 	if (!visited[i]) dfs(i);
	}
	for (int i = 0; i < save.size(); i++) {
	 	int u = save[i][0];
	 	int v = save[i][1];
	 	int range = save[i][2];
	 	if (dist[u] + range != dist[v]) {
	 	 	cout << "NO" << endl;
	 	 	return;
	 	}
	}
	cout << "YES" << endl;
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

