/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 22.03.2025 22:15:00
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
vector<int> A[N];
int n, m , k;
int numb[N], low[N];
int timeDfs = 0;
bool deleted[N];
vector<int> sVertex;
stack<int> store;
int root[N], cnt[N];
set<int> witnesses[N];
vector<int> adj[N];

void reset(void) {
	timeDfs = 0;
	sVertex.clear();
	while (!store.empty()) store.pop();
 	for (int i = 1; i <= n; i++) {
 	 	A[i].clear();
 	 	witnesses[i].clear();
 	 	adj[i].clear();
 	 	numb[i] = 0;
 	 	cnt[i] = 0;
 	 	root[i] = 0;
 	 	low[i] = 0;
 	 	deleted[i] = false;
 	}
}

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
		sVertex.push_back(u);
		while (!store.empty()) {
		 	int temp = store.top();
		 	store.pop();
		 	deleted[temp] = true;
			root[temp] = u;
			witnesses[u].insert(temp);
			if (temp == u) break;
		}
 	}
}

void dfs_group(int u) {
 	if (witnesses[u].size() > k) return;
 	for (int i = 0; i < adj[u].size(); i++) {
 	 	int v = adj[u][i];
 	 	dfs_group(v);
 	 	for (int w : witnesses[v]) {
 	 	 	if (witnesses[u].size() > k) break;
 	 	 	witnesses[u].insert(w);
 	 	}
 	}
}

void solve(void) {
 	cin >> n >> m >> k;
 	reset();
 	for (int i = 1; i <= m; i++) {
 	 	int a, b;
 	 	cin >> a >> b;
 	 	A[a].push_back(b);
 	}
 	for (int i = 1; i <= n; i++) {
 	 	if (numb[i] != 0) continue;
 	 	dfs(i);
 	}
 	for (int u = 1; u <= n; u++) {
 	 	int rootU = root[u];
 	 	for (int i = 0; i < A[u].size(); i++) {
 	 	 	int v = A[u][i];
 	 	 	int rootV = root[v];
 	 	 	if (rootU != rootV) {
 	 	 		adj[rootV].push_back(rootU);
 	 	 	}	
 	 	}
 	}
 	for (int s : sVertex) {
 	 	cnt[s] = witnesses[s].size();
 	}
 	for (int s : sVertex) {
 	 	dfs_group(s);
 	}
 	int ret = 0;
 	for (int s : sVertex) {
 	 	if (witnesses[s].size() > k) {
 	 	 	ret += cnt[s];
 	 	}
 	}
 	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
	 	solve();
	}

	return 0;
}
