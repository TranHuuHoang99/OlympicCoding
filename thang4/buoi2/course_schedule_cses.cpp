/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 07.03.2025 19:56:38
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
vector<int> A[N];
int n, m;
int state[N];
stack<int> ret;

void dfs(int u) {
	state[u] = 1;
	for (int i = 0; i < A[u].size(); i++) {
	 	int v = A[u][i];
	 	if (state[v] == 0) {
			dfs(v);
	 	} else if (state[v] == 1) {
	 	 	cout << "IMPOSSIBLE" << endl;
	 	 	exit(0);
	 	}
	}
	ret.push(u);
	state[u] = 2;
}

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
	 	int a, b;
	 	cin >> a >> b;
	 	A[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
	 	if (state[i] == 0) {
	 	 	dfs(i);
	 	}
	}
	while (!ret.empty()) {
	 	cout << ret.top() << ' ';
	 	ret.pop();
	}
	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
