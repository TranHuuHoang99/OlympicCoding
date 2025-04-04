/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 04.04.2025 21:29:58
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e3+10;
vector<int> A[N];
int n, m, numb[N], low[N];
bool deleted[N];
stack<int> store;
int timeDfs = 0;
int root[N];
vector<int> suRoot;
int src[N], des[N];

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
 		suRoot.push_back(u);
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
	 	int rootu = root[u];
	 	for (int i = 0; i < A[u].size(); i++) {
	 	 	int v = A[u][i];
	 	 	int rootv = root[v];
	 	 	if (rootu != rootv) {
				src[rootv]++;
				des[rootu]++;
	 	 	}
	 	}
	}
	int numbStart = 0;
	int numbEnd = 0;
	int start, end;
	for (int suR : suRoot) {
	 	if (src[suR] == 0) {
	 	 	numbStart++;
	 	 	start = suR;
	 	}
	 	if (des[suR] == 0) {
	 	 	numbEnd++;
	 	 	end = suR;
	 	}
	}
	if (numbStart != 1 || numbEnd != 1) {
	 	cout << "NO" << endl;
	 	return;
	}
	cout << "YES" << endl;
	cout << end << ' ' << start << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
