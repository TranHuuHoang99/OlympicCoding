/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 11.03.2025 20:45:42
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
const ll M = 2e5+10;
vector<int> A[N];
int n, m;
int numb[N], low[N];
set<int> joint;
vector<pair<int,int>> bridge;
int timeDfs = 0;

void dfs(int u, int prev) {
	timeDfs++;
	numb[u] = low[u] = timeDfs;
	int numbChildren = 0;
	for (int i = 0; i < A[u].size(); i++) {
	 	int v = A[u][i];
	 	if (v == prev) continue;
	 	if (numb[v] == 0) {
			numbChildren++;
			if (u == 1 && numbChildren > 1) {
			 	joint.insert(u);
			}
			dfs(v,u);
			if (numb[v] == low[v]) {
				bridge.push_back({min(u,v), max(u,v)});
			}
			if (u != 1 && low[v] >= numb[u]) {
			 	joint.insert(u);
			}
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
	cout << joint.size() << endl;
	for (int e : joint) cout << e << ' ';
	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
