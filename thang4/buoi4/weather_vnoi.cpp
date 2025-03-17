/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 17.03.2025 19:25:31
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e2+10;
vector<int> A[N];
int n, m, numb[N], low[N];
int timeDfs = 0, ret = 0;
int bridge[N];

void dfs(int u, int prev) {
	timeDfs++;
	numb[u] = low[u] = timeDfs;
	bridge[u] = 1;
	for (int i = 0; i < A[u].size(); i++) {
	 	int v = A[u][i];
	 	if (v == prev) continue;
	 	if (numb[v] == 0) {
	 	 	dfs(v, u);
	 	 	if (numb[v] == low[v]) {
	 	 	 	ret += bridge[v] * (n-bridge[v]);
	 	 	}
	 	 	bridge[u] += bridge[v];
	 	 	low[u] = min(low[u], low[v]);
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
 	dfs(1,1);
 	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
