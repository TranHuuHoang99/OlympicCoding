/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-27 13:40:55 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n, q;
int A[N];
int it[4*N];
int dist[N];
int F[N][20];
vector<int> adj[N];
// heavy light decomposition
int chain = 1;
int chainStart[N];
int chainIndex[N];
int position[N];
int sz[N];
vector<int> listVertex;
int parent[N];
// end

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
 	 	 	if (ancestor != -1 && F[ancestor][j-1]) {
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

void update(int idx, int left, int right, int pos, int val) {
 	if (pos > right || pos < left) return;
 	if (left == right) {
 	 	it[idx] = val;
 	 	return;
 	}
 	int mid = (left+right)>>1;
 	update(idx*2, left, mid, pos, val);
 	update(idx*2+1, mid+1, right, pos, val);
 	it[idx] = max(it[idx*2], it[idx*2+1]);
}

int get_val(int idx, int left, int right, int u, int v) {
 	if (u > right || v < left) return 0;
 	if (u <= left && right <= v) return it[idx];
 	int mid = (left+right)>>1;
 	int left_val = get_val(idx*2, left, mid, u, v);
 	int right_val = get_val(idx*2+1, mid+1, right, u, v);
 	return max(left_val, right_val);
}

void solve(void) {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		chainStart[i] = -1;
	}
	for (int i = 1; i < n; i++) {
	 	int u, v;
	 	cin >> u >> v;
	 	adj[u].push_back(v);
	 	adj[v].push_back(u);
	}
	dfs(1, -1);
	HLD(1, -1);
	build_ancestor();
	for (int i = 1; i <= n; i++) {
	 	int pos = position[i];
	 	update(1, 1, n, pos, A[i]);
	}
	for (int i = 1; i <= q; i++) {
	 	int type;
	 	cin >> type;
	 	if (type == 1) {
	 	 	int node, val;
	 	 	cin >> node >> val;
	 	 	int pos = position[node];
	 	 	update(1, 1, n, pos, val);
	 	} else {
	 	 	int u, v;
	 	 	cin >> u >> v;
	 	 	int ancestor = lca(u, v);
	 	 	int ret = -1;
	 	 	while (chainIndex[u] != chainIndex[ancestor]) {
	 	 	 	int right = position[u];
	 	 	 	u = chainStart[chainIndex[u]];
	 	 	 	int left = position[u];
	 	 	 	ret = max(ret, get_val(1, 1, n, left, right));
	 	 	 	u = parent[u]; 
	 	 	}
	 	 	ret = max(ret, get_val(1, 1, n, position[ancestor], position[u]));
	 	 	while (chainIndex[v] != chainIndex[ancestor]) {
	 	 	 	int right = position[v];
	 	 	 	v = chainStart[chainIndex[v]];
	 	 	 	int left = position[v];
	 	 	 	ret = max(ret, get_val(1, 1, n, left, right));
	 	 	 	v = parent[v];
	 	 	}
	 	 	ret = max(ret, get_val(1, 1, n, position[ancestor], position[v]));
	 	 	cout << ret << ' ';
	 	}
	}
	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}













































