/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 11.03.2025 21:08:21
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
vector<int> A[N];
int n, m;
int numb[N], low[N];
int timeDfs = 0;
int bridge = 0;
map<int,bool> myMap[N];

void dfs(int u, int prev) {
 	timeDfs++;
 	numb[u] = low[u] = timeDfs;
 	for (int i = 0; i < A[u].size(); i++) {
 	 	int v = A[u][i];
 	 	if (numb[v] == 0) {
 	 	 	dfs(v,u);
 	 	 	if (u != 1 && low[v] >= numb[u]) {
 	 	 	 	if (myMap[u][v]) continue;
 	 	 	 	bridge++;
 	 	 	}
 	 	 	low[u] = min(low[u], low[v]);
 	 	} else {
 	 	 	low[u] = min(low[u], numb[v]);
 	 	}
 	}
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n-1; i++) {
	 	int a, b;
	 	cin >> a >> b;
	 	A[a].push_back(b);
	 	A[b].push_back(a);
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
	 	int a, b;
	 	cin >> a >> b;
	 	A[a].push_back(b);
	 	A[b].push_back(a);
	 	myMap[a][b] = true;
	 	myMap[b][a] = true;
	}
	dfs(1,1);
	cout << bridge << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
