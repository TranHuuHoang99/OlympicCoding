/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-30 21:22:01 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
int n;
vector<int> adj[N];
int sz[N];
void dfs_sz_root(int u, int father) {
 	sz[u] = 1;
 	for (int v : adj[u]) {
 	 	if (v == father) continue;
 	 	dfs_sz_root(v, u);
 	 	sz[u] += sz[v];
 	}
}
int findCentroidRoot(int u, int father) {
	for (int v : adj[u]) {
	 	if (v == father) continue;
	 	if (2 * sz[v] > n) return findCentroidRoot(v, u);
	}
	return u;
}
int dfs_sz(int u, int father) {
 	sz[u] = 1;
 	for (int v : adj[u]) {
 	 	if (v == father || visited[v] == true) continue;
 	 	dfs_sz(v, u);
 	 	sz[u] += sz[v];
 	}
}
int findCentroid(int u, int father, int numb) {
 	for (int v : adj[u]) {
 	 	if (v == father || visited[v] == true) continue;
 	 	if (2 * sz[v] > numb) return findCentroid(v, u, numb);
 	}
 	return u;
}
void dfs(int u, int father) {
 	dfs_sz(u, father);
 	int centroid = findCentroid(u, father, sz[u]);
 	visited[centroid] = true;
 	for (int v : adj[centroid]) {
 	 	if (visited[v] == true) continue;
 	 	dfs(v, centroid);
 	}
}
void solve(void) {
	cin >> n;
	for (int i = 1; i < n; i++) {
	 	int u, v;
	 	cin >> u >> v;
	 	adj[u].push_back(v);
	 	adj[v].push_back(u);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}





































































