/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 20.03.2025 23:01:17
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
ll coins[N];
ll f[N], dp[N];
int n, m, numb[N], low[N];
vector<int> A[N];
bool deleted[N], visited[N];
int root[N];
int timeDfs = 0;
stack<int> store;
vector<int> trace[N];
stack<int> topo;

void dfs(int u) {
 	timeDfs++;
 	numb[u] = low[u] = timeDfs;
 	store.push(u);
 	for (int i = 0; i < A[u].size(); i++) {
 	 	int v = A[u][i];
 	 	if (deleted[v]) continue;
 	 	if (numb[v] == 0) {
 	 	 	dfs(v);
 	 	 	low[u] = min(low[u], low[v]);
 	 	} else {
 	 	 	low[u] = min(low[u], numb[v]);
 	 	}
 	}
 	if (numb[u] == low[u]) {
 	 	while (!store.empty()) {
 	 	 	int temp = store.top();
 	 	 	store.pop();
 	 	 	deleted[temp] = true;
 	 	 	f[u] += coins[temp];
 	 	 	root[temp] = u;
 	 	 	if (temp == u) break;
 	 	}
 	}
}

void dfs_topo(int u) {
 	visited[u] = true;
 	for (int i = 0; i < trace[u].size(); i++) {
 	 	int v = trace[u][i];
 	 	if (visited[v]) continue;
 	 	dfs_topo(v);
 	}
 	topo.push(u);
}

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> coins[i];
	for (int i = 1; i <= m; i++) {
	 	int a, b;
	 	cin >> a >> b;
	 	A[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
	 	if (numb[i] != 0) continue;
	 	dfs(i);
	}
	set<int> master;
	for (int u = 1; u <= n; u++) {
		int rootU = root[u];
		master.insert(rootU);
		for (int i = 0; i < A[u].size(); i++) {
		 	int v = A[u][i];
		 	int rootV = root[v];
		 	if (rootU != rootV) {
		 	 	trace[rootU].push_back(rootV);
		 	}
		}
	}
	for (int e : master) {
	 	if (visited[e]) continue;
	 	dfs_topo(e);
	}
	vector<int> temp;
	while (!topo.empty()) {
	 	temp.push_back(topo.top());
	 	topo.pop();
	}
	for (int i = 0; i < temp.size(); i++) {
	 	int u = temp[i];
	 	dp[u] = max(dp[u], f[u]);
	 	for (int j = 0; j < trace[u].size(); j++) {
	 		int v = trace[u][j];
			dp[v] = max(dp[v], dp[u] + f[v]);
	 	}
	}
	ll ret = 0;
	for (int e : master) ret = max(ret, dp[e]);
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
