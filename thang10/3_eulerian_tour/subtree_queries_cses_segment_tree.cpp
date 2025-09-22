/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-20 12:31:36 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n, q;
vector<int> adj[N];
int left_node[N], right_node[N];
ll A[N];
int timeDfs;
ll it[4*N];

void dfs(int u, int parent) {
 	timeDfs++;
 	left_node[u] = timeDfs;
 	for (int v : adj[u]) {
 	 	if (v == parent) continue;
 	 	dfs(v,u);
	}
	right_node[u] = timeDfs;
}

void update(int idx, int left, int right, int u, int v, ll val) {
 	if (u > right || v < left) return;
 	if (u <= left && right <= v) {
 	 	it[idx] += val;
 	 	return;
 	}
 	int mid = (left+right)>>1;
 	update(idx*2, left, mid, u, v, val);
 	update(idx*2+1, mid+1, right, u, v, val);
 	it[idx] = it[idx*2] + it[idx*2+1];
}

ll get_val(int idx, int left, int right, int u, int v) {
 	if (u > right || v < left) return 0ll;
 	if (u <= left && right <= v) return it[idx];
 	int mid = (left+right)>>1;
 	ll left_val = get_val(idx*2, left, mid, u, v);
 	ll right_val = get_val(idx*2+1, mid+1, right, u, v);
 	return left_val + right_val;
}

void solve(void) {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n-1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);	
	}
	timeDfs = 0;
	dfs(1,1);
	for (int i = 1; i <= n; i++) {
	 	update(1, 1, n, left_node[i], left_node[i], A[i]);
	}
	for (int i = 1; i <= q; i++) {
	 	int type;
	 	cin >> type;
	 	if (type == 1) {
	 	 	int node;
	 	 	ll val;
	 	 	cin >> node >> val;
	 	 	update(1, 1, n, left_node[node], left_node[node], val-A[node]);
	 	 	A[node] = val;
	 	} else {
	 	 	int node;
	 	 	cin >> node;
	 	 	ll val = get_val(1, 1, n, left_node[node], right_node[node]);
	 	 	cout << val << endl;
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

