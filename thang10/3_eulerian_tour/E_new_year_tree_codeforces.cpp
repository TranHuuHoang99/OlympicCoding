/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-20 13:46:19 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 4e5+10;
int n, m;
vector<int> adj[N];
int left_node[N], right_node[N];
int A[N];
int it[4*N];
int lazy[4*N];
int timeDfs;

void dfs(int u, int parent) {
 	timeDfs++;
 	left_node[u] = timeDfs;
 	for (int v : adj[u]) {
 	 	if (v == parent) continue;
 	 	dfs(v, u);
 	}
 	right_node[u] = timeDfs;
}

void lazy_update(int idx) {
 	if (lazy[idx] > 0ll) {
 	 	it[idx*2] = lazy[idx];
 	 	it[idx*2+1] = lazy[idx];
		lazy[idx*2] = lazy[idx];
		lazy[idx*2+1] = lazy[idx];
		lazy[idx] = 0ll;
 	}
}

void update(int idx, int left, int right, int u, int v, int val) {
 	if (u > right || v < left) return;
 	if (u <= left && right <= v) {
		it[idx] = val;
		lazy[idx] = val;
		return;
 	}
	int mid = (left+right)>>1;
	lazy_update(idx);
	update(idx*2, left, mid, u, v, val);
	update(idx*2+1, mid+1, right, u, v, val);
	it[idx] = it[idx*2] | it[idx*2+1];
}

int get_val(int idx, int left, int right, int u, int v) {
 	if (u > right || v < left) return 0ll;
 	if (u <= left && right <= v) return it[idx];
 	int mid = (left+right)>>1;
 	lazy_update(idx);
 	int left_val = get_val(idx*2, left, mid, u, v);
 	int right_val = get_val(idx*2+1, mid+1, right, u, v);
 	return left_val | right_val;
}

void solve(void) {
 	cin >> n >> m;
 	for (int i = 1; i <= n; i++) {
 	 	int color;
 	 	cin >> color;
 	 	A[i] = (1ll << color);
 	}
 	for (int i = 1; i <= n-1; i++) {
 		int u, v;
 		cin >> u >> v;
 		adj[u].push_back(v);
 		adj[v].push_back(u);
 	}
 	timeDfs = 0ll;
 	dfs(1,1);
 	for (int i = 1; i <= n; i++) {
 	 	update(1, 1, n, left_node[i], left_node[i], A[i]);
 	}
 	for (int i = 1; i <= m; i++) {
 	 	int type;
 	 	cin >> type;
 	 	if (type == 1) {
 	 	 	int node, color;
 	 	 	cin >> node >> color;
 	 	 	int val = (1ll << color);
 	 	 	update(1, 1, n, left_node[node], right_node[node], val);
 		} else {
 		 	int node;
 		 	cin >> node;
 		 	int val = get_val(1, 1, n, left_node[node], right_node[node]);
 		 	int ret = 0;
 		 	for (int idx = 0; idx <= 60; idx++) {
 		 	 	if (val & (1ll << idx)) {
 		 	 	 	ret++;
 		 	 	}
 		 	}
 			cout << ret << endl;
 		}
 	}
}

signed main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}














