/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-07 20:26:29 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 210;
int n, m;
vector<int> adj[N];
set<int> save[N];
int numb[N];
void dfs(int u, int father) {
	numb[u] += 1;
	for (int v : adj[u]) {
	 	if (v == father) continue;
	 	dfs(v, u);
	 	numb[u] += numb[v];
	 	save[u].insert(numb[v]);
	}
}
void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
	 	adj[i].clear();
	}
	for (int i = 1; i <= m; i++) {
	 	int u, v;
	 	cin >> u >> v;
	 	adj[u].push_back(v);
	 	adj[v].push_back(u);
	}
	for (int u = 1; u <= n; u++) {
		for (int i = 1; i <= n; i++) {
		 	save[i].clear();
		 	numb[i] = 0;
		}
		if (adj[u].size() <= 1) continue;
		dfs(u,-1);
		if (save[u].size() == 1) {
		 	int v = adj[u][0];
		 	cout << adj[u].size() << ' ' << adj[v].size()-1 << endl;
		 	return;
		}
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

