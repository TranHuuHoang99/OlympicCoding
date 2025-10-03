/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-03 10:45:01 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
int n, m;
vector<int> adj[N];
int sz[N];
int visited[N];
int parent[N]; // use this to switch between to centroid
map<int,int> dist[N]; 
int minDist[N];
void dfs_sz(int u, int father) {
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
		if (sz[v] * 2 >= numb) return findCentroid(v, u, numb);
 	}
 	return u;
}
void dfs_dist(int u, int father, int centroid, int curDist) {
	dist[centroid][u] = curDist;
	for (int v : adj[u]) {
	    if (v == father || visited[v] == true) continue;
	    dfs_dist(v, u, centroid, curDist+1);
	}	
}
void centroidDecomposition(int u, int father) {
 	dfs_sz(u, father);
 	int centroid = findCentroid(u, father, sz[u]);
 	visited[centroid] = true;
 	parent[centroid] = father;
 	dfs_dist(centroid, -1, centroid, 0);
 	for (int v : adj[centroid]) {
 	 	if (v == father || visited[v] == true) continue;
 	 	centroidDecomposition(v, centroid);
 	}
}
void markRedColor(int u) {
 	int v = u;
 	while (v != -1) {
 	 	minDist[v] = min(minDist[v], dist[v][u]);
 	 	v = parent[v];
 	}
}
void solve(void) {
 	cin >> n >> m;
 	for (int i = 1; i <= n; i++) minDist[i] = n+10;
 	for (int i = 1; i < n; i++) {
 		int u, v;
 		cin >> u >> v;
 		adj[u].push_back(v);
 		adj[v].push_back(u);
   	}
   	centroidDecomposition(1, -1);
   	markRedColor(1);
   	for (int i = 1; i <= m; i++) {
   	 	int type, u;
   	 	cin >> type >> u;
		if (type == 1) {
			markRedColor(u);
		} else {
		 	int v = u;
		 	int ret = minDist[u];
		 	while (v != -1) {
		 	 	ret = min(ret, minDist[v] + dist[v][u]);
		 	 	v = parent[v];
		 	}
		 	cout << ret << endl;
		}
   	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}





































