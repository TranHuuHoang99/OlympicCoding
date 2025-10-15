/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-10 20:45:01 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
  	int u, v, weight;
};
const ll N = 1e3+10;
const ll M = 1e4+10;
int root[N];
int used[M];
int n, m, k;
vector<Node> adj;

int findRoot(int u) {
 	if (u == root[u]) return u;
 	return root[u] = findRoot(root[u]);
}

bool cmp(Node a, Node b) {
 	return a.weight < b.weight;
}

void solve(void) {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
	 	int u, v;
	 	cin >> u >> v;
	 	adj.push_back((Node){u, v, i});
	}
	sort(adj.begin(), adj.end(), cmp);
	while (k--) {
	 	for (int i = 1; i <= n; i++) {
	 	 	root[i] = i;
	 	}
		int cnt = 0;
		int sum = 0;
		for (int i = 0; i < adj.size(); i++) {
			Node neighbor = adj[i];
			if (used[neighbor.weight] == true) continue;
			if (cnt == 0) {
			 	used[neighbor.weight] = true;
			}
			int u = neighbor.u;
			int v = neighbor.v;
			int rootu = findRoot(u);
			int rootv = findRoot(v);
			if (rootu != rootv) {
			 	root[rootu] = rootv;
			 	sum += neighbor.weight;
			 	cnt++;
			}
		}
		if (cnt == n-1) {
		 	cout << sum << endl;
		} else {
		 	cout << 0 << endl;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}








































