#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
  	int rootU, backRootU, backRankU, backParityU;
  	int rootV, backRootV, backRankV, backParityV;
  	int backNumbComp;
  	int backParityCycle;
};
const ll N = 2e5+10;
int n, q;
vector<pair<int,int>> it[4*N];
int adj[N], lastExist[N], root[N], dsu_rank[N], parity[N];
int ans[N];
int numbComp, parityCycle;
stack<Node> st;

void update(int idx, int left, int right, int start, int end, int u, int v) {
 	if (start > right || end < left) return;
 	if (start <= left && right <= end) {
 	 	it[idx].push_back({u,v});
 	 	return;
 	}
 	int mid = (left+right)/2;
 	update(idx*2, left, mid, start, end, u, v);
 	update(idx*2+1, mid+1, right, start, end, u, v);
}

void unite_node(int u, int v) {
 	int rootU = u;
 	int parityU = parity[rootU];
 	while (rootU != root[rootU]) {
 	 	rootU = root[rootU];
 	 	parityU ^= parity[rootU];
	}
	int rootV = v;
	int parityV = parity[rootV];
	while (rootV != root[rootV]) {
	 	rootV = root[rootV];
	 	parityV ^= parity[rootV];
	}
	if (rootU == rootV) {
	 	if (parityU == parityV) {
	 	 	Node temp;
	 	 	temp.rootU = rootU;
	 	 	temp.backRootU = root[rootU];
	 	 	temp.backRankU = dsu_rank[rootU];
	 	 	temp.backParityU = parity[rootU];
	 	 	temp.rootV = rootV;
	 	 	temp.backRootV = root[rootV];
	 	 	temp.backRankV = dsu_rank[rootV];
	 	 	temp.backParityV = parity[rootV];
	 	 	temp.backNumbComp = numbComp;
	 	 	temp.backParityCycle = parityCycle;
	 	 	st.push(temp);
	 	 	parityCycle ^= 1;
	 	}
	 	return;
	}
	if (dsu_rank[rootU] < dsu_rank[rootV]) swap(rootU, rootV);
	Node temp;
	temp.rootU = rootU;
	temp.backRootU = root[rootU];
	temp.backRankU = dsu_rank[rootU];
	temp.backParityU = parity[rootU];
	temp.rootV = rootV;
	temp.backRootV = root[rootV];
	temp.backRankV = dsu_rank[rootV];
	temp.backParityV = parity[rootV];
	temp.backNumbComp = numbComp;
	temp.backParityCycle = parityCycle;
	st.push(temp);
	numbComp--;
	if (dsu_rank[rootU] == dsu_rank[rootV]) {
	 	dsu_rank[rootU]++;
	}
	if (parityU == parityV) {
	 	parity[rootV] ^= 1;
	}
	root[rootV] = rootU;
}

void rollback(int backSize) {
 	while (st.size() > backSize) {
 	    Node temp = st.top();
 	    st.pop();
		int rootU = temp.rootU;
		int backRankU = temp.backRankU;
		int backRootU = temp.backRootU;
		int backParityU = temp.backParityU;
		int rootV = temp.rootV;
		int backRootV = temp.backRootV;
		int backRankV = temp.backRankV;
		int backParityV = temp.backParityV;
		numbComp = temp.backNumbComp;
		parityCycle = temp.backParityCycle;
		root[rootU] = backRootU;
		dsu_rank[rootU] = backRankU;
		parity[rootU] = backParityU;
		root[rootV] = backRootV;
		dsu_rank[rootV] = backRankV;
		parity[rootV] = backParityV;
 	}	
}

void process(int idx, int left, int right, int backSize) {
 	for (pair<int,int> p : it[idx]) {
 	 	auto [u,v] = p;
 	 	unite_node(u, v);
 	}
 	if (left == right) {
 	 	if (ans[left] == 2) {
 	 	 	int numb = (n+parityCycle+numbComp);
 	 	 	if (numb % 2 == 0) {
 	 	 	 	ans[left] = 1;
 	 	 	} else {
 	 	 	 	ans[left] = 2;	
 	 	 	}
 	 	}
 	} else {
 	 	int mid = (left+right)/2;
 	 	process(idx*2, left, mid, st.size());
 	 	process(idx*2+1, mid+1, right, st.size());
 	}
 	rollback(backSize);
}

void solve(void) {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
	 	cin >> adj[i];
	 	lastExist[i] = 0;
	 	root[i] = i;
	 	dsu_rank[i] = 0;
	 	parity[i] = 0;
	}
	for (int i = 1; i <= q; i++) {
	 	int u, v, k;
	 	cin >> u >> v >> k;
	 	ans[i] = k%3;
	 	update(1, 0, q, lastExist[u], i-1, u, adj[u]);
	 	adj[u] = v;
	 	lastExist[u] = i;
	}
	for (int u = 1; u <= n; u++) {
	 	update(1, 0, q, lastExist[u], q, u, adj[u]);
	}
	numbComp = n;
	parityCycle = 0;
	process(1, 0, q, 0);
	for (int i = 1; i <= q; i++) cout << ans[i] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG
	solve();
	return 0;
}

