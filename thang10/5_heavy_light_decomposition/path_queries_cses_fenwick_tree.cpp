/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-26 20:58:13 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
vector<int> adj[N];
/*
*******************************************************************
	Heavy Light Decomposition Implementation
*******************************************************************
*/
int chain = 1; // use for tracking the current chain in a tree
int chainIndex[N]; // use for determine which chain is current vertex are belong to
int chainStart[N]; // use for storing the root vertex in that chain
int sz[N]; // use for tracking how many child vertex that root vertex has
int position[N]; // use for tracking the position of the vertex in the array, after flattern a tree into an array
int parent[N]; // use for tracking the parent of current vertex
vector<int> listVertex; // use for store the current vertex into an array, we use this for control the position array above

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
// ****************************************************************

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
ll fw[N]; // using fenwick tree to store all the value

void update_fenwick(int idx, const int& val) {
 	for (int i = idx; i <= 2e5; i+=i&-i) {
 	 	fw[i] += val;
 	}
}

ll get_fenwick(int idx) {
    ll ret = 0ll;
    for (int i = idx; i > 0; i -=i&-i) {
     	ret += fw[i];
    }
    return ret;
}	

void solve(void) {
 	cin >> n >> q;
 	for (int i = 1; i <= q; i++) {
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
		update_fenwick(pos, A[i]);
 	}
 	for (int i = 1; i <= q; i++) {
 	 	int type;
 	 	cin >> type;
 	 	if (type == 1) {
 	 	 	int node, val;
 	 	 	cin >> node >> val;
 	 	 	int pos = position[node];
			update_fenwick(pos, val - A[node]);
			A[node] = val;
 	 	} else {
 	 	 	int node;
 	 	 	cin >> node;
 	 	 	ll ret = 0ll;
 	 	 	while (chainIndex[node] != 1) {
 	 	 	 	int right = position[node];
 	 	 	 	node = chainStart[chainIndex[node]];
 	 	 	 	int left = position[node];
 	 	 	 	ret += get_fenwick(right) - get_fenwick(left-1);
 	 	 	 	node = parent[node];
 	 	 	}
 	 	 	ret += get_fenwick(position[node]);
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













































