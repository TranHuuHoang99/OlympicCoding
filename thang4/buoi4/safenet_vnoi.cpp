/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 18.03.2025 19:08:23
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e4+10;
int n, m, numb[N], low[N];
vector<int> A[N];
int timeDfs = 0;
int ret = 0;
stack<int> store;

void dfs(int u, int prev) {
	timeDfs++;
	numb[u] = low[u] = timeDfs;
	if (A[u].empty()) {
	 	ret = max(ret, 1);
	 	return;
	}
	store.push(u);
	for (int i = 0; i < A[u].size(); i++) {
	 	int v = A[u][i];
	 	if (v == prev) continue;
	 	if (numb[v] == 0) {
	 	 	dfs(v,u);
	 	 	low[u] = min(low[u], low[v]);
			if (prev == -1 || low[v] >= numb[u]) {
			 	int cnt = 1;
			 	while (!store.empty()) {
			 	 	int temp = store.top();
			 	 	store.pop();
			 	 	cnt++;
			 	 	if (temp == v) break;
			 	}
			 	ret = max(ret, cnt);
			}
	 	} else {
	 	 	low[u] = min(low[u], numb[v]);
	 	}
	}
}

void solve(void) {
 	cin >> n >> m;
 	for (int i = 1; i <= m; i++) {
 	 	int a, b;
 	 	cin >> a >> b;
 	 	A[a].push_back(b);
 	 	A[b].push_back(a);
 	}
 	for (int i = 1; i <= n; i++) {
 	 	if (numb[i] != 0) continue;
 	 	dfs(i,-1);
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
