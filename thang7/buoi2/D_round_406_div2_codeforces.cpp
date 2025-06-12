#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int n, q, s;
vector<pair<int,ll>> it[9*N];
ll dist[9*N];

void build(int idx, int left, int right) {
 	if (left == right) {
 	    it[idx+n].push_back({left, 0ll});
 	    it[left].push_back({idx+5*n, 0ll});
 	    return;
 	}	
 	it[idx+n].push_back({idx*2+n, 0ll});
 	it[idx+n].push_back({idx*2+1+n, 0ll});
 	it[idx*2+5*n].push_back({idx+5*n, 0ll});
 	it[idx*2+1+5*n].push_back({idx+5*n, 0ll});
 	int mid = (left+right)/2;
 	build(idx*2, left, mid);
 	build(idx*2+1, mid+1, right);
}

void process2(int idx, int left, int right, int u, int v, int pos, ll val) {
 	if (u > right || v < left) return;
 	if (u <= left && right <= v) {
 	 	it[pos].push_back({idx+n, val});
 	 	return;
 	}
 	int mid = (left+right)/2;
 	process2(idx*2, left, mid, u, v, pos, val);
 	process2(idx*2+1, mid+1, right, u, v, pos, val);
}

void process3(int idx, int left, int right, int u, int v, int pos, ll val) {
    if (u > right || v < left) return;
    if (u <= left && right <= v) {
     	it[idx+5*n].push_back({pos,val});
     	return;
    }
    int mid = (left+right)/2;
    process3(idx*2, left, mid, u, v, pos, val);
    process3(idx*2+1, mid+1, right, u, v, pos, val);
}

// find the shortest path
void dijkstra(int start) {
 	for (int i = 0; i <= 9*n; i++) dist[i] = LLONG_MAX;
 	dist[start] = 0ll;
 	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
 	pq.push({0ll, start});
 	while (!pq.empty()) {
 	 	pair<ll,int> temp = pq.top();
 	 	pq.pop();
 	 	if (temp.first != dist[temp.second]) continue;
 	 	int u = temp.second;
 	 	for (int i = 0; i < it[u].size(); i++) {
 	 	    int v = it[u][i].first;
 	 	    ll weight = it[u][i].second;
 	 	    if (dist[v] > dist[u] + weight) {
 	 	        dist[v] = dist[u] + weight;
 	 	        pq.push({dist[v], v});
 	 	    }	
 	 	}	
 	}
}

void solve(void) {
	cin >> n >> q >> s;
	build(1, 1, n);
	for (int i = 1; i <= q; i++) {
	 	int type;
	 	cin >> type;
	 	if (type == 1) {
	 	 	int u, v;
	 	 	ll weight;
	 	 	cin >> u >> v >> weight;
 			it[u].push_back({v,weight});
	 	} else if (type == 2) {
	 	    int u;
	 	    int left, right;
	 	    ll weight;
	 	    cin >> u >> left >> right >> weight;
	 	    process2(1, 1, n, left, right, u, weight);
	 	} else {
	 	 	int u;
	 	 	int left, right;
	 	 	ll weight;
	 	 	cin >> u >> left >> right >> weight;
	 	 	process3(1, 1, n, left, right, u, weight);
		}
	}
	dijkstra(s);
	for (int i = 1; i <= n; i++) {
		cout << (dist[i] == LLONG_MAX ? -1 : dist[i]) << endl;
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
	solve();

	return 0;
}
















