/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 09.03.2025 22:38:26
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
 	int x1, y1, x2, y2;
};

const ll N = 110;
const ll M = 2010;
int A[N][N];
bool visited[M];
set<int> adj[M];
int n, m;
Node trace[M];
stack<int> ret;

void dfs(int u) {
 	visited[u] = true;
 	for (int v : adj[u]) {
 	 	if (!visited[v]) dfs(v);
 	}
 	ret.push(u);
}

void solve(void) {
	cin >> n >> m;
	set<int> color;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	cin >> A[i][j];
	 	 	color.insert(A[i][j]);
	 	}
	}
	memset(visited,false,sizeof(visited));
	for (int i = 0; i <= 2000; i++) adj[i].clear();
	for (int c : color) {
	 	int x1 = M, y1 = M, x2 = -1, y2 = -1;
	 	for (int i = 1; i <= n; i++) {
	 	    for (int j = 1; j <= m; j++) {
	 	     	if (A[i][j] == c) {
	 	     	 	x1 = min(x1, i);
	 	     	 	y1 = min(y1, j);
	 	     	 	x2 = max(x2, i);
	 	     	 	y2 = max(y2, j);
	 	     	}
	 	    }
	 	}	
	 	if (x2 == -1) continue;
	 	for (int x = x1; x <= x2; x++) {
	 	 	for (int y = y1; y <= y2; y++) {
	 	 	 	if (A[x][y] != c) {
	 	 	 	 	adj[c].insert(A[x][y]);
	 	 	 	}
	 	 	}
	 	}
	 	trace[c] = (Node){x1,y1,x2,y2};
	}
	for (int c : color) {
		if (!visited[c]) dfs(c);
	}
	cout << ret.size() << endl;
	while (!ret.empty()) {
	 	int temp = ret.top();
	 	ret.pop();
	 	Node ret_color = trace[temp];
	 	cout << ret_color.x1 << ' ' << ret_color.y1 << ' ' << ret_color.x2 << ' ' << ret_color.y2 << ' ' << temp << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}
