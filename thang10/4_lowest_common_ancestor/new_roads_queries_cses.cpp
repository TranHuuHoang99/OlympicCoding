/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-25 20:30:05 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n, m, q;
vector<pair<int,int>> adj[N];
int dist[N];
int F[N][17], weight[N][17];
int root[N];

int findRoot(int u) {
 	if (u == root[u]) return u;
 	return root[u] = findRoot(root[u]);
}

void dfs(int u, int parent) {
 	F[u][0] = parent;
 	for (pair<int,int> temp : adj[u]) {
 	 	int v = temp.first;
 	 	int timeLine = temp.second;
 	 	if (v == parent) continue;
 	 	dist[v] = dist[u] + 1;
 	 	weight[v][0] = timeLine;
 	 	dfs(v, u);
 	}
}

int lca(int u, int v) {
 	if (dist[u] < dist[v]) swap(u, v);
 	for (int j = 16; j >= 0; j--) {
 	 	if (dist[u] - (1 << j) >= dist[v]) {
 	 	 	u = F[u][j];
 	 	}
 	}
 	if (u == v) return u;
 	for (int j = 16; j >= 0; j--) {
 	 	if (F[u][j] != -1 && F[v][j] != -1 && F[u][j] != F[v][j]) {
 	 	 	u = F[u][j];
 	 	 	v = F[v][j];
 	 	}
 	}
 	return F[u][0];
}

void build_ancestor(void) {
 	for (int j = 1; j <= 16; j++) {
 	 	for (int i = 1; i <= n; i++) {
 	 	 	int ancestor = F[i][j-1];
 	 	 	if (ancestor != -1 && F[ancestor][j-1] != -1) {
 	 	 	 	weight[i][j] = max(weight[i][j-1], weight[ancestor][j-1]);
 	 	 	 	F[i][j] = F[ancestor][j-1];
 	 	 	}
 	 	}
 	}
}

void solve(void) {
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
	 	root[i] = i;
	 	F[i][0] = -1;
	 	weight[i][0] = -1;
	}
	for (int i = 1; i <= m; i++) {
	 	int u, v;
	 	cin >> u >> v;
	 	int rootu = findRoot(u);
	 	int rootv = findRoot(v);
	 	if (rootu != rootv) {
	 	 	root[rootu] = rootv;
	 	 	adj[u].push_back({v, i});
	 	 	adj[v].push_back({u, i});
	 	}
	}
	for (int u = 1; u <= n; u++) {
	 	if (F[u][0] == -1) {
	 	 	dist[u] = 0;
	 	 	dfs(u, -1);
	 	}
	}
	build_ancestor();
	for (int i = 1; i <= q; i++) {
	 	int u, v;
	 	cin >> u >> v;
	 	if (u == v) {
	 	 	cout << 0 << endl;
	 	 	continue;
	 	}
	 	int rootu = findRoot(u);
	 	int rootv = findRoot(v);
	 	if (rootu != rootv) {
	 	 	cout << -1 << endl;
	 	 	continue;
	 	}
	 	int ancestor = lca(u, v);
	 	int ret = -1;
	 	for (int j = 16; j >= 0; j--) {
	 	 	if (dist[u] - (1 << j) >= dist[ancestor]) {
	 	 		ret = max(ret, weight[u][j]);
	 	 	 	u = F[u][j];
	 	 	}
	 	 	if (dist[v] - (1 << j) >= dist[ancestor]) {
	 	 	 	ret = max(ret, weight[v][j]);
	 	 	 	v = F[v][j];
	 	 	}
	 	}
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


















