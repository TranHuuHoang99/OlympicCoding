/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 11.03.2025 20:30:46
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
vector<pair<int,int>> bridge;
bool isJoint[N];
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
				isJoint[u] = true;
	 	 	}
	 		dfs(v, u);
	 		if (low[v] == numb[v]) {
				bridge.push_back({min(u,v),max(u,v)});	 		 	
	 		}
	 		if (u != 1 && low[v] >= numb[u]) {
	 	 	 	isJoint[u] = true;
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
	cout << bridge.size() << endl;
	for (int i = 0; i < bridge.size(); i++) {
	 	auto [x,y] = bridge[i];
	 	cout << x << ' ' << y << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
