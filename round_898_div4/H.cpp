/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-15 10:48:17 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n, a, b;
vector<int> adj[N];
bool visited[N];
int entry;
bool dfs(int u, int father) {
 	visited[u] = true;
 	for (int v : adj[u]) {
 	 	if (v == father) continue;
 	 	if (visited[v]) {
 	 	 	entry = v;
			return true;
 	 	}
		if (dfs(v, u)) return true;
 	}
 	return false;
}
void bfs(int u, vector<int>& dist) {
 	dist[u] = 0;
 	queue<int> q;
 	q.push(u);
 	while (!q.empty()) {
 		int u = q.front();
 		q.pop();
 		for (int v : adj[u]) {
 		 	if (dist[v] > dist[u] + 1) {
 		 	 	dist[v] = dist[u] + 1;
 		 	 	q.push(v);
 		 	}
 		}
	}
}
void solve(void) {
 	cin >> n >> a >> b;
 	for (int i = 1; i <= n; i++) {
 	 	adj[i].clear();
 	 	visited[i] = false;
 	}
 	for (int i = 1; i <= n; i++) {
 	 	int u, v;
 	 	cin >> u >> v;
 	 	adj[u].push_back(v);
 	 	adj[v].push_back(u);
 	}
 	dfs(b, -1);
 	vector<int> dist_a(n+1, INT32_MAX);
 	vector<int> dist_b(n+1, INT32_MAX);
 	bfs(a, dist_a);
 	bfs(b, dist_b);
 	if (dist_a[entry] > dist_b[entry]) {
 	 	cout << "YES" << endl;
 	} else {
 	 	cout << "NO" << endl;
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
 