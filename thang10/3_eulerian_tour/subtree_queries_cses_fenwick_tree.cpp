/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-20 13:32:39 
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
ll fw[N];
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

void update(int idx, ll val) {
 	for (int i = idx; i <= n; i+=i&-i) {
 	 	fw[i] += val;
 	}
}

ll get_val(int left_idx, int right_idx) {
 	ll right_val = 0ll;
 	for (int i = right_idx; i >= 1; i-=i&-i) {
 	 	right_val += fw[i];
 	}
 	ll left_val = 0ll;
 	for (int i = left_idx; i >= 1; i-=i&-i) {
 	 	left_val += fw[i];
 	}
 	return right_val - left_val;
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
	 	update(left_node[i], A[i]);
	}
	for (int i = 1; i <= q; i++) {
	 	int type;
	 	cin >> type;
	 	if (type == 1) {
	 	 	int node;
	 	 	ll val;
	 	 	cin >> node >> val;
	 	 	update(left_node[node], val - A[node]);
			A[node] = val;
	 	} else {
			int node;
			cin >> node;
			ll ret = get_val(left_node[node]-1, right_node[node]);
			cout << ret << endl; 
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







