/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-21 10:07:58 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 5e5+10;
int n, q;
vector<int> adj[N];
vector<int> it_fill, it_empty;
vector<int> lazy_fill, lazy_empty;
int left_node[N], right_node[N];
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

void lazy_update(int idx, vector<int>& lazy, vector<int>& it) {
 	if (lazy[idx] != -1) {
 	 	it[idx*2] = lazy[idx];
 	 	it[idx*2+1] = lazy[idx];
 	 	lazy[idx*2] = lazy[idx];
 	 	lazy[idx*2+1] = lazy[idx];
 	 	lazy[idx] = -1;
 	}
}

void update(int idx, int left, int right, int u, int v, vector<int>& lazy, vector<int>& it, int val) {
 	if (u > right || v < left) return;
 	if (u <= left && right <= v) {
 	 	it[idx] = val;
 	 	lazy[idx] = val;
 	 	return;
 	}
 	int mid = (left+right)>>1;
 	lazy_update(idx, lazy, it);
 	update(idx*2, left, mid, u, v, lazy, it, val);
 	update(idx*2+1, mid+1, right, u, v, lazy, it, val);
 	it[idx] = max(it[idx*2], it[idx*2+1]);
}

int get_val(int idx, int left, int right, int u, int v, vector<int>& lazy, vector<int>& it) {
 	if (u > right || v < left) return -1;
 	if (u <= left && right <= v) return it[idx];
 	int mid = (left+right)>>1;
 	lazy_update(idx, lazy, it);
 	int left_val = get_val(idx*2, left, mid, u, v, lazy, it);
 	int right_val = get_val(idx*2+1, mid+1, right, u, v, lazy, it);
 	return max(left_val, right_val);
}

void solve(void) {
 	cin >> n;
 	int len = n*4+10;
 	it_fill.assign(len, 0);
 	it_empty.assign(len, 0);
 	lazy_fill.assign(len, -1);
 	lazy_empty.assign(len, -1);
 	for (int i = 1; i <= n-1; i++) {
 	 	int u, v;
 	 	cin >> u >> v;
 	 	adj[u].push_back(v);
 	 	adj[v].push_back(u);
 	}
 	timeDfs = 0;
 	dfs(1,1);
 	cin >> q;
 	for (int i = 1; i <= q; i++) {
 		int type;
 		int node;
 		cin >> type >> node;
 		if (type == 1) {
 		 	update(1, 1, n, left_node[node], right_node[node], lazy_fill, it_fill, i);
 		} else if (type == 2) {
 		 	update(1, 1, n, left_node[node], left_node[node], lazy_empty, it_empty, i);
 		} else {
 		 	int fill_timeLine = get_val(1, 1, n, left_node[node], left_node[node], lazy_fill, it_fill);
 		 	int empty_timeLine = get_val(1, 1, n, left_node[node], right_node[node], lazy_empty, it_empty);
 		 	if (fill_timeLine == 0 || empty_timeLine > fill_timeLine) {
 		 	 	cout << 0 << endl;
 		 	} else {
 		 	 	cout << 1 << endl;
 		 	}
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

