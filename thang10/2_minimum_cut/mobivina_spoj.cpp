/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-16 21:22:02 
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
  	vector<int> cnt;
  	Dinic(int _source, int _sink, int _numbVertex) {
  	 	source = _source;
  	 	sink = _sink;
  	 	numbVertex = _numbVertex;
  	 	adj.clear();
  	 	adj.resize(numbVertex);
  	 	level.clear();
  	 	level.resize(numbVertex);
  	 	cnt.clear();
  	 	cnt.resize(numbVertex);
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
  	int sendFlow(int u, int curFlow) {
  	 	if (u == sink) return curFlow;
  	 	for ( ; cnt[u] < adj[u].size(); cnt[u]++) {
  	 	 	Edge& neighbor = adj[u][cnt[u]];
  	 	 	if (neighbor.flow < neighbor.capacity && level[neighbor.des] == level[u] + 1) {
  	 	 	 	int flow = sendFlow(neighbor.des, min(curFlow, neighbor.capacity - neighbor.flow));
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
  	 	 	for (int i = 0; i < numbVertex; i++) cnt[i] = 0;
  	 	 	while (true) {
  	 	 	    int flow = sendFlow(source, INT32_MAX);
  	 	 	    if (flow == 0) break;
  	 	 	    ret += flow;
  	 	 	}	
  	 	}
  	 	return ret;
  	}
};
int n;
int source, sink;

void solve(void) {
	cin >> n;
	int max_len = n*2+10;
	source = 0;
	sink = max_len - 1;
	Dinic sol(source, sink, max_len);
	for (int i = 1; i <= n; i++) {
	 	int weight;
	 	cin >> weight;
	 	sol.addEdge(source, i, weight);
	}
	for (int i = 1; i <= n; i++) {
	 	int weight;
	 	cin >> weight;
	 	sol.addEdge(i, sink, weight);
	}
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= n; j++) {
	 	 	int weight;
	 	 	cin >> weight;
	 	 	sol.addEdge(i, j, weight);
	 	}
	}
	cout << sol.maxFlow() << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

















