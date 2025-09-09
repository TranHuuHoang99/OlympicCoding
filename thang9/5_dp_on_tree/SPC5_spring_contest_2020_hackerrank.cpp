/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-26 20:23:44 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
int n;
ll A[N];
vector<int> adj[N];
ll size_node[N];
ll dp_out[N];
ll dp_in[N];

void dfs_size(int u, int parent) {
 	size_node[u] = 1ll;
 	for (int v : adj[u]) {
 	 	if (v == parent) continue;
 	 	dfs_size(v, u);
 	 	size_node[u] += size_node[v];
 	}
}

void dfs_out(int u, int parent) {
 	for (int v : adj[u]) {
 	 	if (v == parent) continue;
 	 	dfs_out(v, u);
 	 	dp_out[u] += dp_out[v] + A[v] + size_node[v] * A[u];
 	}
}

void dfs_in(int u, int parent) {
 	for (int v : adj[u]) {
 	 	if (v == parent) continue;
 	 	dp_in[v] += dp_in[u] + dp_out[u] - dp_out[v] - A[v] - size_node[v] * A[u] + A[u] + A[v] * (n-size_node[v]);
 	 	dfs_in(v, u);
 	}
}

void solve(void) {
 	cin >> n;
 	for (int i = 1; i <= n; i++) {
 	 	adj[i].clear();
 	 	size_node[i] = 0ll;
 	 	dp_out[i] = 0ll;
 	 	dp_in[i] = 0ll;
 	 	cin >> A[i];
 	}
 	for (int i = 1; i <= n-1; i++) {
 	 	int u, v;
 	 	cin >> u >> v;
 	 	adj[u].push_back(v);
 	 	adj[v].push_back(u);
 	}
 	dfs_size(1, 1);
 	dfs_out(1, 1);
 	dfs_in(1, 1);
 	for (int i = 1; i <= n; i++) cout << (dp_out[i] + dp_in[i]) << ' ';
 	cout << endl;
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

