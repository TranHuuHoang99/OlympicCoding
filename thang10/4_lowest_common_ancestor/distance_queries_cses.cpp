/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-23 20:17:50 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n, q;
vector<int> adj[N];
int F[N][20];
int parent[N];
int dist[N];

void dfs(int u, int ancestor) {
 	parent[u] = ancestor;
 	for (int v : adj[u]) {
 	    if (v == ancestor) continue;
 	    dist[v] = dist[u] + 1;
 	    dfs(v, u);
 	}	
}

int lca(int u, int v) {
 	if (dist[u] < dist[v]) swap(u, v);
 	for (int j = 19; j >= 0; j--) {
 	 	if (dist[u] - (1<<j) >= dist[v]) {
 	 	 	u = F[u][j];
 	 	}
 	}
 	if (u == v) return u;
 	for (int j = 19; j >= 0; j--) {
 	 	if (F[u][j] != -1 && F[v][j] != -1 && F[u][j] != F[v][j]) {
 	 	 	u = F[u][j];
 	 	 	v = F[v][j];
 	 	}
 	}
 	return F[u][0]; // or return F[v][0]
}

void solve(void) {
 	cin >> n >> q;
 	for (int i = 1; i < n; i++) {
 	 	int u, v;
 	 	cin >> u >> v;
 	 	adj[u].push_back(v);
 	 	adj[v].push_back(u);
 	}
	dist[1] = 0;
	dfs(1,-1);
	for (int i = 1; i <= n; i++) {
	 	F[i][0] = parent[i];
	}
	for (int j = 1; j <= 19; j++) {
	 	for (int i = 1; i <= n; i++) {
	 	 	int ancestor = F[i][j-1];
	 	 	if (ancestor != -1 && F[ancestor][j-1] != -1) {
	 	 	    F[i][j] = F[ancestor][j-1];
	 	 	}	
	 	}
	}
	for (int i = 1; i <= q; i++) {
	 	int u, v;
	 	cin >> u >> v;
	 	int common_ancestor = lca(u, v);
	 	int ret = dist[u] + dist[v] - 2 * dist[common_ancestor];
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

