/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-19 19:20:40 
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
  	int inf;
  	vector<vector<Edge>> adj;
  	vector<int> level;
  	vector<int> cnt;
  	Dinic(int _source, int _sink, int _numbVertex, int _inf) {
  	 	source = _source;
  	 	sink = _sink;
  	 	numbVertex = _numbVertex;
  	 	inf = _inf;
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
  	 	 	 	int flow = sendFlow(source, inf);
  	 	 	 	if (flow == 0) break;
  	 	 	 	ret += flow;
  	 	 	}
  	 	}
  	 	return ret;
  	}
};
int n, m, A, B;
int source, sink;
char matrix[55][55];
int moves[5] = {1,0,-1,0,1};

int calculateID(int x, int y) {
 	return (x-1) * m + y;
}

void solve(void) {
	cin >> n >> m >> A >> B;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	cin >> matrix[i][j];
	 	}
	}
	int len = n*m+100;
	source = 0;
	sink = len - 1;
	Dinic sol(source, sink, len, INT32_MAX);
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	if (matrix[i][j] == '.') {
	 	 	 	sol.addEdge(source, calculateID(i,j), B);
	 	 	} else {
	 	 	 	sol.addEdge(calculateID(i,j), sink, B);
	 	 	}
	 	 	for (int idx = 0; idx < 4; idx++) {
	 	 	 	int ver = i + moves[idx];
	 	 	 	int hor = j + moves[idx+1];
	 	 	 	if (ver >= 1 && ver <= n && hor >= 1 && hor <= m) {
	 	 	 	 	sol.addEdge(calculateID(i,j), calculateID(ver,hor), A);
	 	 	 	}
	 	 	}
	 	}
	}
	int ret = sol.maxFlow();
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


























