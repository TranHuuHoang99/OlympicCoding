/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-27 13:22:33 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
vector<int> adj[N];

/*
	Heavy Light Decomposition Implementation Start
*/	
int chain = 1;
int chainStart[N];
int chainIndex[N];
int position[N];
int sz[N];
int parent[N];
vector<int> listVertex;

void HLD(int u, int father) {
 	if (chainStart[chain] == -1) {
 	 	chainStart[chain] = u;
 	}
 	chainIndex[u] = chain;
 	listVertex.push_back(u);
 	position[u] = (int)listVertex.size();
 	int specialVertex = -1;
 	for (int v : adj[u]) {
 	 	if (v == father) continue;
 	 	if (specialVertex == -1 || sz[specialVertex] < sz[v]) {
 	 	 	specialVertex = v;
 	 	}
 	}
 	if (specialVertex != -1) {
 	 	HLD(specialVertex, u);
 	}
 	for (int v : adj[u]) {
 	 	if (v == father || v == specialVertex) continue;
 	 	chain++;
 	 	HLD(v, u);
 	}
}
/*
	Heavy Light Decomposition Implementation Stop
*/

void dfs(int u, int father) {
 	parent[u] = father;
 	sz[u] = 1;
 	for (int v : adj[u]) {
 	 	if (v == father) continue;
 	 	dfs(v, u);
 	 	sz[u] += sz[v];
 	}
}

int n, q;
int A[N];
ll it[4*N];

void update(int idx, int left, int right, int u, int v, const int& val) {
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
	for (int i = 1; i <= n; i++) {
	 	chainStart[i] = -1;
	}
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);	
   	}
   	dfs(1, -1);
   	HLD(1, -1);
   	for (int i = 1; i <= n; i++) {
   	 	int pos = position[i];
   	 	update(1, 1, n, pos, pos, A[i]);
   	}
   	for (int i = 1; i <= q; i++) {
   	 	int type;
   	 	cin >> type;
   	 	if (type == 1) {
   	 	 	int node, val;
   	 	 	cin >> node >> val;
   	 	 	int pos = position[node];
   	 	 	update(1, 1, n, pos, pos, val - A[node]);
   	 	 	A[node] = val;
   	 	} else {
   	 		int node;
   	 		cin >> node;
   	 		ll ret = 0ll;
   	 		while (chainIndex[node] != 1) {
   	 		 	int right = position[node];
   	 		 	node = chainStart[chainIndex[node]];
   	 		 	int left = position[node];
   	 		 	ret += get_val(1, 1, n, left, right);
   	 		 	node = parent[node];
   	 		}
   	 		ret += get_val(1, 1, n, 1, position[node]);
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





































