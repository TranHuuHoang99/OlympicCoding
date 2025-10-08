/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-07 20:38:03 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge {
  	int des, capacity, flow, id;
};
struct Dinic {
  	int source, sink;
  	int numbVertex;
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
		 	 	 	revertEdge.capacity += flow;
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
const int N = 60;
int n, m;
ll parkCost, skyCost;
int A[N][N];
bool visited[N][N];
int moves[5] = {1,0,-1,0,1};
set<ll> prices;

void solve(void) {
	cin >> n >> m >> parkCost >> skyCost;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	cin >> A[i][j];
	 	 	prices.insert(A[i][j]);
	 	}
	}
	prices.insert(0ll);
	int max_len = n*m+m;
	int source = 0;
	int sink = max_len - 1;
	queue<pair<int,int>> q;
	ll ret = LLONG_MAX;
	for (long long Z : prices) {
	 	int parkLand = 0;
	 	vector<int> color(max_len, -1);
	 	for (int i = 1; i <= n; i++) {
	 	 	for (int j = 1; j <= m; j++) {
	 	 	 	if (A[i][j] > Z) {
					int cur_id = (i-1)*m + j;
					color[cur_id] = (i+j)&1; // set this node to be black or white
					parkLand++;	 	 	 		
	 	 	 	}
	 	 	}
	 	}
	 	if (parkLand % 2 != 0) continue;
	 	Dinic sol(source, sink, max_len, INT32_MAX);
	 	for (int i = 1; i <= n; i++) {
	 	 	for (int j = 1; j <= m; j++) {
	 	 	 	int cur_id = (i-1)*m+j;
	 	 	 	if (color[cur_id] == 0) {
	 	 	 		sol.addEdge(source, cur_id, 1);
	 	 	 	 	for (int idx = 0; idx < 4; idx++) {
	 	 	 	 	 	int ver = i + moves[idx];
	 	 	 	 	 	int hor = j + moves[idx+1];
	 	 	 	 	 	if (ver < 1 || ver > n || hor < 1 || hor > m) continue;
	 	 	 	 	 	int next_id = (ver-1)*m+hor;
	 	 	 	 	 	if (color[next_id] < 0) continue;
	 	 	 	 	 	sol.addEdge(cur_id, next_id, 1);
	 	 	 	 	}
	 	 	 	} else {
	 	 	 	 	sol.addEdge(cur_id, sink, 1);
	 	 	 	}
	 	 	}
	 	}
	 	int maxMatching = sol.maxFlow();
	 	if (maxMatching * 2 == parkLand && maxMatching != 0) {
	 		ll cost = parkCost * maxMatching + skyCost * Z;
			ret = min(ret, cost);
	 	}
	 	if (parkLand == 0) ret = min(ret, skyCost * Z);
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}






































