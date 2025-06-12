#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e5+10;
int L[N], R[N];
vector<pair<int,int>> save;
vector<pair<int,int>> it[6*N];
int dist[6*N];
int n;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first > b.first;
}	

void build(int idx, int left, int right, int vertex) {
 	if (vertex > right || vertex < left) return;
 	it[vertex].push_back({idx+n, 0});
 	if (left == right) return;
 	int mid = (left+right)/2;
 	build(idx*2, left, mid, vertex);
 	build(idx*2+1, mid+1, right, vertex);
}

void process(int idx, int left, int right, int u, int v, int vertex) {
    if (u > right || v < left) return;
    if (u <= left && right <= v) {
     	it[idx+n].push_back({vertex,1});
     	return;
    }
    int mid = (left+right)/2;
    process(idx*2, left, mid, u, v, vertex);
    process(idx*2+1, mid+1, right, u, v, vertex);
}	

// bfs 0-1 to travel all vertex
void bfs01(void) {
 	for (int i = 0; i <= 6*n; i++) dist[i] = INT32_MAX;
	for (int i = 0; i < save.size(); i++) {
		if (dist[save[i].second] != INT32_MAX) continue;
		deque<int> dq;
	    for (int j = i; j < save.size(); j++) {
	     	if (save[i].first == save[j].first && dist[save[j].second] == INT32_MAX) {
				dq.push_front(save[j].second);
				dist[save[j].second] = 0;				     	 	
	     	} else {
	     	 	i = j-1;
	     	 	break;
	     	}
	    }
	    while (!dq.empty()) {
	        int u = dq.front();
	        dq.pop_front();
	        for (int j = 0; j < it[u].size(); j++) {
	         	auto [v,weight] = it[u][j];
	         	if (dist[v] > dist[u] + weight) {
	         		dist[v] = dist[u] + weight;
	         	 	if (weight == 0) {
	         	 	 	dq.push_front(v);
	         	 	} else {
	         	 	    dq.push_back(v);
	         	 	}	
	         	}
	        }
	    }	
	}	
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
	 	int temp;
	 	cin >> temp;
	 	save.push_back({temp,i});
	}
	for (int i = 1; i <= n; i++) cin >> L[i] >> R[i];
	sort(save.begin(), save.end(), cmp);
	for (int i = 1; i <= n; i++) build(1, 1, n, i);
	for (int i = 1; i <= n; i++) process(1, 1, n, L[i], R[i], i);
	bfs01();
	int ret = -1;
	for (int i = 1; i <= n; i++) ret = max(ret, dist[i]);
	cout << (ret+1) << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("INCOME.INP", "r", stdin);
	freopen("INCOME.OUT", "w", stdout);
	solve();
	return 0;
}

