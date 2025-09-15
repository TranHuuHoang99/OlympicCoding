/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-14 12:59:39 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge {
    int des, capacity, flow, id;
};
struct Dinic {
  	int numbVertex;
  	int source, sink;
  	vector<vector<Edge>> adj;
  	vector<int> level;
  	Dinic(int _source, int _sink, int _numbVertex) {
  	 	numbVertex = _numbVertex;
  	 	source = _source;
  	 	sink = _sink;
  	 	adj.clear();
  	 	adj.resize(numbVertex);
  	 	level.clear();
  	 	level.resize(numbVertex);
  	}
  	void addEdge(int u, int v, int weight) {
  	 	int size_u = adj[u].size();
  	 	int size_v = adj[v].size();
  	 	adj[u].push_back((Edge){v, weight, 0, size_v});
  	 	adj[v].push_back((Edge){u, 0, 0, size_u});
  	}
  	bool bfs(void) {
  	 	for (int i = 0; i < level.size(); i++) {
  	 	 	level[i] = -1;
  	 	}
  	 	level[source] = 0;
  	 	queue<int> q;
  	 	q.push(source);
  	 	while (!q.empty()) {
  	 	 	int u = q.front();
  	 	 	q.pop();
  	 	 	for (int i = 0; i < adj[u].size(); i++) {
  	 	 	 	Edge neighbor = adj[u][i];
  	 	 	 	if (neighbor.flow < neighbor.capacity && level[neighbor.des] == -1) {
  	 	 	 	 	level[neighbor.des] = level[u] + 1;
  	 	 	 	 	q.push(neighbor.des);
  	 	 	 	}
  	 	 	}
  	 	}
  	 	return level[sink] != -1;
  	}
  	int sendFlow(int u, int curFlow, vector<int>& cnt) {
  	 	if (u == sink) return curFlow;
  	 	for ( ; cnt[u] < adj[u].size(); cnt[u]++) {
  	 	 	Edge& neighbor = adj[u][cnt[u]];
  	 	 	if (neighbor.flow < neighbor.capacity && level[neighbor.des] == level[u] + 1) {
  	 	 	 	int flow = sendFlow(neighbor.des, min(curFlow, neighbor.capacity - neighbor.flow), cnt);
  	 	 	 	if (flow > 0) {
  	 	 	 	 	neighbor.flow += flow;
  	 	 	 	 	Edge& revertEdge = adj[neighbor.des][neighbor.id];
  	 	 	 	 	revertEdge.flow -= flow;
  	 	 	 	 	return flow;
  	 	 	 	}
  	 	 	}
  	 	}
  	 	return 0;
  	}
  	int maxFlow(void) {
  	 	int ret = 0;
  	 	while (bfs()) {
  	 	 	while (true) {
  	 	 		vector<int> cnt(numbVertex, 0);
  	 	 	 	int flow = sendFlow(source, INT32_MAX, cnt);
  	 	 	 	if (flow == 0) break;
  	 	 	 	ret += flow; 
  	 	 	}
  	 	}
  	 	return ret;
  	}
};
int n, m;
int u, v;
int source, sink;

void solve(void) {
 	cin >> n >> m;
 	int max_len = n+m+10;
 	source = 0;
 	sink = max_len-1;
 	Dinic sol(source, sink, max_len);
 	while (cin >> u >> v) {
		sol.addEdge(u, v+n, 1);
 	}
 	for (int u = 1; u <= n; u++) {
 	 	sol.addEdge(source, u, 1);
 	}
 	for (int v = 1; v <= m; v++) {
 	 	sol.addEdge(v+n, sink, 1);
 	}
 	int ret = sol.maxFlow();
 	cout << ret << endl;
 	vector<pair<int,int>> ret_pair;
	for (int u = 1; u <= n; u++) {
	 	for (int i = 0; i < sol.adj[u].size(); i++) {
	 	 	Edge neighbor = sol.adj[u][i];
	 	 	if (neighbor.flow > 0) {
	 	 	 	ret_pair.push_back({u, neighbor.des});
	 	 	}
	 	}
	}
	for (int i = 0; i < ret_pair.size(); i++) {
	 	cout << ret_pair[i].first << ' ' << ret_pair[i].second - n << endl;
	}
}	

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

