/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-12 20:35:02 
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
  	 	source = _source;
  	 	sink = _sink;
  	 	numbVertex = _numbVertex;
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
const ll N = 30;
int n, m;
int source, sink;
int A[N][N];
vector<tuple<int,int,int>> save[5];
int steps[5] = {1,0,-1,0,1};

void solve(void) {
 	cin >> n >> m;
 	for (int i = 1; i <= n; i++) {
 	 	for (int j = 1; j <= m; j++) {
 	 	 	char c;
 	 	 	cin >> c;
 	 	 	int val = int(c-'a'+1);
			A[i][j] = val;
			save[val].push_back({i, j, (i-1)*m + j});
 	 	}
 	}
 	int max_len = n*m+m+10;
 	source = 0;
 	sink = max_len-1;
 	Dinic sol(source, sink, max_len);
 	for (int type = 1; type <= 4; type++) {	
 	 	for (int i = 0; i < save[type].size(); i++) {
 	 	 	for (int j = 0; j < 4; j++) {
				int ver = get<0>(save[type][i]) + steps[j];
				int hor = get<1>(save[type][i]) + steps[j+1];
				if (ver < 1 || ver > n || hor < 1 || hor > m) continue;
				if (A[ver][hor] == type+1) {
				 	sol.addEdge(get<2>(save[type][i]), (ver-1)*m+hor, 1);
				}
 	 	 	}
 	 	}
 	}
	for (int i = 0; i < save[1].size(); i++) {
	 	sol.addEdge(source, get<2>(save[1][i]), 1);
	}
	for (int i = 0; i < save[4].size(); i++) {
	 	sol.addEdge(get<2>(save[4][i]), sink, 1);
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

























