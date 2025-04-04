/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 04.04.2025 19:51:09
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e6+10;
vector<int> A[N];
int n, c;
int dis[N];

void dfs(int u) {
	for (int i = 0; i < A[u].size(); i++) {
	 	int v = A[u][i];
	 	dis[v] = dis[u] + 1;
	 	dfs(v);
	}
}

void solve(void) {
	cin >> n >> c;
	for (int i = 1; i <= c; i++) {
	 	int a, b, d;
	 	cin >> a >> b >> d;
	 	A[a].push_back(b);
	 	A[a].push_back(d);
	}
	dis[1] = 1;
	dfs(1);
	for (int i = 1; i <= n; i++) cout << dis[i] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
