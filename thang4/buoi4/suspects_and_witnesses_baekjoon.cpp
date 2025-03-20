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
int n, m, k, numb[N], low[N];
bool deleted[N];
int timeDfs = 0;
stack<int> store;
int root[N], cnt[N];
int master = 0;
set<int> witnesses[N];
vector<int> adj[N];

void reset(void) {
	for (int i = 1; i <= n; i++) {
	 	A[i].clear();
	 	adj[i].clear();
	 	numb[i] = low[i] = 0;
	 	deleted[i] = false;
	 	root[i] = 0;
	 	cnt[i] = 0;
	 	witnesses[i].clear();
	}
	master = 0;
	timeDfs = 0;
	while (!store.empty()) store.pop();
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
	 	master++;
	 	while (!store.empty()) {
	 	 	int temp = store.top();
	 	 	store.pop();
	 	 	deleted[temp] = true;
	 	 	witnesses[master].insert(temp);
	 	 	root[temp] = master;
	 	 	if (temp == u) break;
	 	}
	}
}

void dfs_group(int u) {
	if (witnesses[u].size() > k) return;
	for (int i = 0; i < adj[u].size(); i++) {
	 	int v = adj[u][i];
	 	dfs_group(v);
	 	for (int e : witnesses[v]) {
			if (witnesses[u].size() > k) break;
			witnesses[u].insert(e); 	 	
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
	n = master;
	for (int i = 1; i <= n; i++) cnt[i] = witnesses[i].size();
	for (int i = 1; i <= n; i++) dfs_group(i);
	int ret = 0;
	for (int i = 1; i <= n; i++) {
	 	if (witnesses[i].size() > k) {
	 	 	ret += cnt[i];
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
