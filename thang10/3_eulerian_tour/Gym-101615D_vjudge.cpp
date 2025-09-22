/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-24 20:44:42 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
  	bool data = false;
  	bool lazy = false;
};
const ll N = 5e4+10;
int n;
vector<pair<int,int>> adj[N];
int left_node[N], right_node[N];
int timeDfs;
map<int,int> colorSame[N];
Node it[4*N];

void lazy_update(int idx) {
	if (it[idx].lazy == true) {
	 	it[idx*2].data = true;
	 	it[idx*2+1].data = true;
	 	it[idx*2].lazy = true;
	 	it[idx*2+1].lazy = true;
	 	it[idx].lazy = false;
	}
}

void update(int idx, int left, int right, int u, int v) {
 	if (u > right || v < left) return;
 	if (u <= left && right <= v) {
 	 	it[idx].data = true;
 	 	it[idx].lazy = true;
 	 	return;
 	}
 	int mid = (left+right)>>1;
 	lazy_update(idx);
 	update(idx*2, left, mid, u, v);
 	update(idx*2+1, mid+1, right, u, v);
 	it[idx].data = (it[idx*2].data == true && it[idx*2+1].data == true);
}

bool isBadNode(int idx, int left, int right, int u, int v) {
 	if (u > right || v < left) return false;
 	if (u <= left && right <= v) return it[idx].data;
 	int mid = (left+right)>>1;
 	lazy_update(idx);
 	bool left_val = isBadNode(idx*2, left, mid, u, v);
 	bool right_val = isBadNode(idx*2+1, mid+1, right, u, v);
 	return left_val == true || right_val == true;
}

void dfs1(int u, int parent) {
 	timeDfs++;
 	left_node[u] = timeDfs;
 	for (pair<int,int> p : adj[u]) {
 	 	int v = p.first;
 	 	int color = p.second;
 	 	if (v == parent) continue;
 	 	colorSame[u][color]++;
 	 	dfs1(v, u);
 	}
 	right_node[u] = timeDfs;
}

void dfs2(int u, int parent, int parentColor) {
 	for (pair<int,int> p : adj[u]) {
 	 	int v = p.first;
 	 	int color = p.second;
 	 	if (v == parent) continue;
 	 	dfs2(v, u, color);
 	 	if (parentColor == color) {
 	 	 	update(1, 1, n, 1, left_node[u]-1);
 	 	 	update(1, 1, n, right_node[u]+1, n);
 	 	 	update(1, 1, n, left_node[v], right_node[v]);	
 	 	}
 	 	if (colorSame[u][color] >= 2) {
 	 	 	update(1, 1, n, left_node[v], right_node[v]);
 	 	}
 	}
}

void solve(void) {
	cin >> n;
	for (int i = 1; i < n; i++) {
	 	int u, v, color;
	 	cin >> u >> v >> color;
	 	adj[u].push_back({v, color});
	 	adj[v].push_back({u, color});
	}
	timeDfs = 0;
	dfs1(1, -1);
	dfs2(1, -1, -1);
	vector<int> ret;
	for (int i = 1; i <= n; i++) {
	 	if (!isBadNode(1, 1, n, left_node[i], left_node[i])) {
	 	 	ret.push_back(i);
	 	}
	}
	cout << ret.size() << endl;
	for (int e : ret) cout << e << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

