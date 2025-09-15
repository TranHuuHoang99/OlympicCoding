/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-12 22:33:28 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edge {
  	int des, capacity, flow, id;
};	
struct Dinic {
  	int numbVertex;
  	vector<vector<Edge>> adj;
  	vector<int> level;
  	int source, sink;
	Dinic(int _numbVertex, int _source, int _sink) {
		numbVertex = _numbVertex;
		source = _source;
		sink = _sink;
		adj.clear();
		adj.resize(_numbVertex);
		level.clear();
		level.resize(_numbVertex);
	}
	void addEdge(int u, int v, int weight) {
	 	int size_u = adj[u].size();
	 	int size_v = adj[v].size();
	 	adj[u].push_back((Edge){v, weight, 0, size_v});
	 	adj[v].push_back((Edge){u, 0, 0, size_u});
	}
	bool bfs(void) {
	 	for (int i = 0; i < numbVertex; i++) level[i] = -1;
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
	 	 	if (level[neighbor.des] == level[u] + 1 && neighbor.flow < neighbor.capacity) {
	 	 	 	int flow = sendFlow(neighbor.des, min(curFlow, neighbor.capacity - neighbor.flow), cnt);
	 	 	 	if (flow > 0) {
	 	 	 	 	neighbor.flow += flow;
	 	 	 	 	Edge& revertEdge = adj[neighbor.des][neighbor.id];
	 	 	 	 	revertEdge.capacity += flow;
	 	 	 	 	return flow;
	 	 	 	}
	 	 	}
	 	}
	 	return 0;
	}
	int maxFlow(void) {
	 	int ret = 0ll;
	 	while (bfs() == true) {
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
int n, m, source, sink;

void solve(void) {
	cin >> n >> m;
	source = 1;
	sink = n;
	Dinic sol(n+10, 1, n);
	for (int i = 1; i <= m; i++) {
	 	int u, v;
	 	int val;
	 	cin >> u >> v >> val;
	 	sol.addEdge(u, v, val);
	}
	int ret = sol.maxFlow();
	cout << ret << endl;
}

signed main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

