/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 07.03.2025 10:38:32
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int state[N];
int trace[N];
int n, m;
vector<int> A[N];

void print(int u, int v) {
	vector<int> ret;
	ret.push_back(v);
	int temp = u;
	while (temp != v) {
	 	ret.push_back(temp);
	 	temp = trace[temp];
	}
	int len = ret.size() + 1;
	cout << len << endl;
	cout << temp << ' ';
	for (int i = ret.size()-1; i >= 0; i--) cout << ret[i] << ' ';
	cout << endl;
}

void dfs(int u) {
 	state[u] = 1;
 	for (int i = 0; i < A[u].size(); i++) {
 	 	int v = A[u][i];
 	 	if (state[v] == 0) {
 	 		trace[v] = u;
 	 	 	dfs(v);
 	 	} else if (state[v] == 1) {
 	 	 	print(u,v);
 	 	 	exit(0);
 	 	}
 	}
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
 	cout << "IMPOSSIBLE" << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
