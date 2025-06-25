#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e4+10;
int n, m, k;
map<string,int> mp;
int moon[N], influence[N];
vector<pair<int,int>> adj[N];
int cost[N];
int dist[N];
int totalMoon[N];

// using bfs to find to total of influence cost
void bfs(int start) {
	if (k == 0) return;
	for (int i = 1; i <= n; i++) dist[i] = -1;
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
	 	int u = q.front();
	 	q.pop();
	 	for (int i = 0; i < adj[u].size(); i++) {
	 	 	int v = adj[u][i].first;
	 	 	if (dist[v] == -1) {
	 	 	 	dist[v] = dist[u] + 1;
	 	 	 	cost[start] += influence[v];
	 	 	 	if (dist[v] < k) {
	 	 	 	 	q.push(v);	
	 	 	 	}
	 	 	}
	 	}
	}
}

void dijkstra(int start, int end) {
	for (int i = 1; i <= n; i++) {
	 	dist[i] = INT32_MAX;
	 	totalMoon[i] = 0;
	}
	totalMoon[start] = moon[start];
	dist[start] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,start});
	while (!pq.empty()) {
		pair<int,int> temp = pq.top();
		pq.pop();
		int u = temp.second;
		if (temp.first != dist[u]) continue;
		for (int i = 0; i < adj[u].size(); i++) {
		 	int v = adj[u][i].first;
		 	int weight = adj[u][i].second;
		 	if (dist[v] > dist[u] + weight) {
		 	 	dist[v] = dist[u] + weight;
		 	 	totalMoon[v] = totalMoon[u] + moon[v];
		 	 	pq.push({dist[v], v});
		 	} else if (dist[v] == dist[u] + weight) {
		 	 	totalMoon[v] = max(totalMoon[v], totalMoon[u] + moon[v]);
		 	}
		}
   }
   cout << dist[end] << ' ' << totalMoon[end] << endl;
} 

void solve(void) {
	cin >> n >> m >> k;
	string start_str, end_str;
	cin >> start_str >> end_str;
	for (int i = 1; i <= n; i++) {
	 	string str;
	 	int a, b;
	 	cin >> str >> a >> b;
	 	mp[str] = i;
	 	moon[i] = a;
	 	influence[i] = b;
	}
	int start = mp[start_str];
	int end = mp[end_str];
	for (int i = 1; i <= m; i++) {
	 	string u_str, v_str;
		int a;
		cin >> u_str >> v_str >> a;
		int u = mp[u_str];
		int v = mp[v_str];
		adj[u].push_back({v,a});
		adj[v].push_back({u,a});
	}
	for (int i = 1; i <= n; i++) bfs(i);
	for (int i = 1; i <= n; i++) {
	 	for (int j = 0; j < adj[i].size(); j++) {
	 	 	adj[i][j].second += cost[i];
	 	}
	}
	dijkstra(start, end);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

