/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-29 21:53:18 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
int n, q;
vector<int> adj[N];
// heavy light decomposition
int chain = 1;
int chainStart[N];
int chainIndex[N];
int position[N];
int sz[N];
int parent[N];
vector<int> listVertex;
// end
int dist[N];
int F[N][20];
void HLD(int u, int father) {
 	if (chainStart[chain] == -1) {
 	 	chainStart[chain] = u;
 	}
 	chainIndex[u] = chain;
 	listVertex.push_back(u);
 	position[u] = (int)listVertex.size();
	int special = -1;
	for (int v : adj[u]) {
	 	if (v == father) continue;
	 	if (special == -1 || sz[special] < sz[v]) {
	 	 	special = v;
	 	}
	}
	if (special != -1) {
	 	HLD(special, u);
	}
	for (int v : adj[u]) {
	 	if (v == father || v == special) continue;
	 	chain++;
	 	HLD(v, u);
	}
}
void dfs(int u, int father) {
 	parent[u] = father;
 	sz[u] = 1;
 	F[u][0] = father;
 	for (int v : adj[u]) {
 	 	if (v == father) continue;
 	 	dist[v] = dist[u] + 1;
 	 	dfs(v, u);
 	 	sz[u] += sz[v];
 	}
}
void build_ancestor(void) {
 	for (int j = 1; j <= 19; j++) {
 	 	for (int i = 1; i <= n; i++) {
 	 	 	int ancestor = F[i][j-1];
 	 	 	if (ancestor != -1 && F[ancestor][j-1] != -1) {
 	 	 	 	F[i][j] = F[ancestor][j-1];
 	 	 	}
 	 	}
 	}
}
int lca(int u, int v) {
 	if (dist[u] < dist[v]) swap(u, v);
 	for (int j = 19; j >= 0; j--) {
 	 	if (dist[u] - (1 << j) >= dist[v]) {
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
 	return F[u][0];
}

void solve(void) {
	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
























































