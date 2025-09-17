/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-16 21:22:56 
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
int n, m, k;
int source, sink;
int moves[5] = {1,0,-1,0,1};
int cost[30];
char A[35][35];

int cal_id(int x, int y) {
 	return (x-1)*m + y;
}

void solve(void) {
	cin >> n >> m >> k;
	swap(n, m);
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	cin >> A[i][j];
	 	}
	}
	for (int i = 0; i < k; i++) cin >> cost[i];
	int len = 2*n*m+100;
	source = 0;
	sink = len-1;
	Dinic sol(source, sink, len, INT32_MAX);
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	if (A[i][j] == 'B') {
	 	 	 	sol.addEdge(source, cal_id(i,j), INT32_MAX);
	 	 	 	sol.addEdge(cal_id(i,j), cal_id(i,j) + n*m, INT32_MAX);
	 	 	} else if ('a' <= A[i][j] && A[i][j] <= 'z') {
	 	 	 	sol.addEdge(cal_id(i,j), cal_id(i,j) + n*m, cost[A[i][j]-'a']);
	 	 	} else {
	 	 	 	sol.addEdge(cal_id(i,j), cal_id(i,j) + n*m, INT32_MAX);
	 	 	}
	 	 	for (int idx = 0; idx < 4; idx++) {
	 	 	 	int ver = i + moves[idx];
	 	 	 	int hor = j + moves[idx+1];
	 	 	 	if (ver >= 1 && ver <= n && hor >= 1 && hor <= m) {
	 	 	 	 	sol.addEdge(cal_id(i,j) + n*m, cal_id(ver,hor), INT32_MAX);
	 	 	 	} else {
	 	 	 	 	sol.addEdge(cal_id(i,j) + n*m, sink, INT32_MAX);
	 	 	 	}
	 	 	}
	 	}
	}
	int ret = sol.maxFlow();
	if (ret == INT32_MAX) {
	 	cout << -1 << endl;
	} else {
	 	cout << ret << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


































