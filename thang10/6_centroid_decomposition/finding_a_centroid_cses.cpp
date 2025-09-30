/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-30 19:59:31 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n;
vector<int> adj[N];
int sz[N];
void dfs(int u, int father) {
 	sz[u] = 1;
 	for (int v : adj[u]) {
 	 	if (v == father) continue;
 	 	dfs(v, u);
 	 	sz[u] += sz[v];
 	}
}
int findCentroid(int u, int father) {
	for (int v : adj[u]) {
	 	if (v == father) continue;
	 	if (2 * sz[v] > n) return findCentroid(v, u);
	}
	return u;
}

void solve(void) {
	cin >> n;
	for (int i = 1; i < n; i++) {
	 	int u, v;
	 	cin >> u >> v;
	 	adj[u].push_back(v);
	 	adj[v].push_back(u);
	}
	dfs(1, -1);
	cout << findCentroid(1, -1) << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

