/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 18.03.2025 20:47:14
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 810;
vector<int> A[N];
int n, m, numb[N], low[N];
int timeDfs = 0;
bool deleted[N];
stack<int> store;
int root[N];
bool bridge[N];

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
 	 	 	root[temp] = u;
 	 	 	if (temp == u) break;
 	 	}
 	}
}

void solve(void) {
 	cin >> n >> m;
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
 	 	 	    bridge[rootV] = true;
 	 	 	}	
 	 	}
 	}
 	int ret = 0;
 	for (int u = 1; u <= n; u++) {
 	 	if (u == root[u] && !bridge[u]) ret++;
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
