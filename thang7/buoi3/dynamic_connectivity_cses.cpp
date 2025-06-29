#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
  	int u, backRootU, backRankU, backNumbComp;
};
const ll N = 1e5+10;
int n, m, k;
map<pair<int,int>, vector<pair<int,int>>> mp;
vector<pair<int,int>> it[4*N];
int numbComp;
int root[N];
int dsu_rank[N];
int ret[N];
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

int findRoot(int u) {
    if (root[u] == u) return u;
    return findRoot(root[u]);
}	

void dsu_rollback(int prevSize) {
 	while (st.size() > prevSize) {
 	 	Node temp = st.top();
 	 	st.pop();
 	 	int u = temp.u;
 	 	int backRootU = temp.backRootU;
 	 	int backRankU = temp.backRankU;
 	 	int backNumbComp = temp.backNumbComp;
 	 	root[u] = backRootU;
 	 	dsu_rank[u] = backRankU;
 	 	numbComp = backNumbComp;
 	}
}

void count_numb_comp(int idx, int left, int right, int prevSize) {
 	for (pair<int,int> p : it[idx]) {
 	 	auto [u,v] = p;
 	 	int rootU = findRoot(u);
 	 	int rootV = findRoot(v);
 	 	if (rootU != rootV) {
 	 	 	if (dsu_rank[rootU] > dsu_rank[rootV]) swap(rootU, rootV);
			root[rootU] = rootV;
			st.push({u, rootU, dsu_rank[rootU], numbComp});			
			if (dsu_rank[rootU] == dsu_rank[rootV]) {
			 	dsu_rank[rootV]++;
			}
			numbComp--;
 	 	}
 	}
 	if (left == right) {
 	 	ret[left] = numbComp;
 	} else {
 	 	int mid = (left + right) / 2;
 	 	count_numb_comp(idx*2, left, mid, st.size());
 	 	count_numb_comp(idx*2+1, mid+1, right, st.size());
 	}
 	dsu_rollback(prevSize);
}

void solve(void) {
 	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
	 	int u, v;
	 	cin >> u >> v;
	 	if (u > v) swap(u, v);
	 	mp[{u,v}].push_back({0,k});
	}
	for (int i = 1; i <= k; i++) {
	    int type;
	    cin >> type;
	    if (type == 1) { // create new edge between vertex u and v
			int u, v;
			cin >> u >> v;
			if (u > v) swap(u, v);
			mp[{u,v}].push_back({i,k});     	
	    } else {
	     	int u, v;
	     	cin >> u >> v;
	     	if (u > v) swap(u, v);
	     	mp[{u,v}].back().second = i-1;
	    }
	}
	for (auto _mp : mp) {
	 	auto [u,v] = _mp.first;
	 	vector<pair<int,int>> timeLine = _mp.second;
	 	for (pair<int,int> t : timeLine) {
	 	 	auto [start, end] = t;
	 	 	update(1, 0, k, start, end, u, v);
	 	}
	}
	numbComp = n;
	for (int i = 1; i <= n; i++) {
	 	root[i] = i;
	 	dsu_rank[i] = 1;
	}
	count_numb_comp(1, 0, k, 0);
	for (int i = 0; i < k; i++) cout << ret[i] << ' ';
	cout << endl;
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

