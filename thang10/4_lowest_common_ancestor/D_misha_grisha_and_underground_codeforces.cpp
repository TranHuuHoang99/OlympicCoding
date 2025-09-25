/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-24 21:30:00 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
int n, q;
vector<int> adj[N];
int dist[N];
int F[N][17];

void dfs(int u, int parent) {
 	F[u][0] = parent;
 	for (int v : adj[u]) {
 	 	if (v == parent) continue;
 	 	dist[v] = dist[u] + 1;
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

int cal_dist(int u, int v) {
 	int ancestor = lca(u, v);
 	return dist[u] + dist[v] - 2 * dist[ancestor] + 1;
}

int process(int a, int b, int c) {
 	int distAB = cal_dist(a, b);
 	int distBC = cal_dist(b, c);
 	int distAC = cal_dist(a, c);
 	int totalRange = (distAB + distBC + distAC) / 2;
 	return distBC + distAC - totalRange;
}

void solve(void) {
	cin >> n >> q;
	for (int u = 2; u <= n; u++) {
	 	int v;
	 	cin >> v;
	 	adj[u].push_back(v);
	 	adj[v].push_back(u);
	}
	dfs(1,-1);
	for (int j = 1; j <= 16; j++) {
	 	for (int i = 1; i <= n; i++) {
	 	 	int ancestor = F[i][j-1];
	 	 	if (ancestor != -1 && F[ancestor][j-1] != -1) {
	 	 	 	F[i][j] = F[ancestor][j-1];
	 	 	}
	 	}
	}
	for (int i = 1; i <= q; i++) {
	 	int a, b, c;
	 	cin >> a >> b >> c;
	 	int ret = 0;
	 	ret = max(ret, process(a, b, c));
	 	ret = max(ret, process(a, c, b));
	 	ret = max(ret, process(b, a, c));
	 	ret = max(ret, process(b, c, a));
	 	ret = max(ret, process(c, a, b));
	 	ret = max(ret, process(c, b, c));
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

