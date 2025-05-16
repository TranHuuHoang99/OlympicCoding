#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 5e4+10;
int n, m;
bitset<N> bs[N];
vector<int> adj[N];
bool visited[N];

void dfs(int u) {
 	visited[u] = true;
 	bitset<N> temp;
 	bs[u].set(u);
 	for (int v : adj[u]) {
 	 	if (visited[v]) {
 	 	 	temp |= bs[v];
 	 	 	continue;
 	 	}
 	 	dfs(v);
 	 	temp |= bs[v];
 	}
 	bs[u] |= temp;
}

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
	 	int u, v;
	 	cin >> u >> v;
	 	adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		dfs(i);
	}
	for (int i = 1; i <= n; i++) {
	 	cout << bs[i].count() << ' ';
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

