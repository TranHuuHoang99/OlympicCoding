/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-26 18:45:31 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n, q;
vector<int> adj[N];
ll prize[N];
ll weight[N][20];
int F[N][20];
int dist[N];
ll ans[N];

void dfs(int u, int parent) {
 	F[u][0] = parent;
 	weight[u][0] = prize[u];
	for (int v : adj[u]) {
	 	if (v == parent) continue;
	 	dist[v] = dist[u] + 1;
	 	dfs(v, u);
	}
}

void build_ancestor(void) {
 	for (int j = 1; j <= 19; j++) {
 	 	for (int i = 1; i <= n; i++) {
 	 	 	int ancestor = F[i][j-1];
 	 	 	if (ancestor != -1 && F[ancestor][j-1] != -1) {
 	 	 	 	F[i][j] = F[ancestor][j-1];
 	 	 	 	weight[i][j] = max(weight[i][j-1], weight[ancestor][j-1]);
 	 	 	}
 	 	}
 	}
}

ll max_lca(int u, int v) {
 	ll ret = -1ll;
 	if (dist[u] < dist[v]) swap(u, v);
 	for (int j = 19; j >= 0; j--) {
 	 	if (dist[u] - (1 << j) >= dist[v]) {
 	 		ret = max(ret, weight[u][j]);
 	 	 	u = F[u][j];
 	 	}
 	}
 	if (u == v) {
 	 	ret = max(ret, prize[u]);
 	 	return ret;
 	}
 	for (int j = 19; j >= 0; j--) {
		if (F[u][j] != -1 && F[v][j] != -1 && F[u][j] != F[v][j]) {
		 	ret = max(ret, weight[u][j]);
		 	ret = max(ret, weight[v][j]);
		 	u = F[u][j];
		 	v = F[v][j];
		}
 	}
 	ret = max(ret, prize[F[u][0]]);
 	ret = max(ret, prize[u]);
 	ret = max(ret, prize[v]);
 	return ret;
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
	 	cin >> prize[i];
	 	ans[i] = -1ll;
	 	F[i][0] = -1;
	}
	for (int i = 1; i < n; i++) {
	 	int u, v;
	 	cin >> u >> v;
	 	adj[u].push_back(v);
	 	adj[v].push_back(u);
	}
	dist[1] = 0;
	dfs(1, -1);
	build_ancestor();
	cin >> q;
	ans[1] = 0ll;
	for (int i = 1; i <= q; i++) {
	 	int u, v;
	 	cin >> u >> v;
	 	ll val = max_lca(u, v);
	 	if (ans[u] != -1ll) {
	 	 	ans[v] = max(ans[v], ans[u] + val);
	 	}
	}
	ll ret = 0ll;
	for (int i = 1; i <= n; i++) {
	 	ret = max(ret, ans[i]);
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("SHIP.inp", "r", stdin);
	freopen("SHIP.out", "w", stdout);
	solve();
	return 0;
}

