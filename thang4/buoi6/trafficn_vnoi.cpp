/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 28.03.2025 20:35:39
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e4+10;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int dis[N], rev_dis[N];
vector<pair<int,int>> A[N];
vector<pair<int,int>> B[N];
vector<tuple<int,int,int>> C;
int n, m, k, s, e;

void solve(void) {
 	cin >> n >> m >> k >> s >> e;
 	for (int i = 1; i <= n; i++) {
 	    dis[i] = INT32_MAX;
 	    rev_dis[i] = INT32_MAX;
 	}	
 	for (int i = 1; i <= n; i++) {
 	 	A[i].clear();
 	 	B[i].clear();
 	}
 	C.clear();
 	for (int i = 1; i <= m; i++) {
 	 	int a, b, c;
 	 	cin >> a >> b >> c;
 	 	A[a].push_back({b,c});
 	 	B[b].push_back({a,c});
	}
	for (int i = 1; i <= k; i++) {
	 	int a, b, c;
	 	cin >> a >> b >> c;
	 	C.push_back({a,b,c});
	}
	dis[s] = 0;
	pq.push({0,s});
	while (!pq.empty()) {
	 	auto [distance, u] = pq.top();
	 	pq.pop();
	 	if (distance != dis[u]) continue;
	 	for (int i = 0; i < A[u].size(); i++) {
	 	 	int v = A[u][i].first;
	 	 	int nextDis = A[u][i].second;
	 	 	if (dis[v] > dis[u] + nextDis) {
	 	 	 	dis[v] = dis[u] + nextDis;
	 	 	 	pq.push({dis[v],v});
	 	 	}
	 	}
	}
	rev_dis[e] = 0;
	pq.push({0,e});
	while (!pq.empty()) {
	 	auto [distance, u] = pq.top();
	 	pq.pop();
	 	if (distance != rev_dis[u]) continue;
	 	for (int i = 0; i < B[u].size(); i++) {
			int v = B[u][i].first;
			int nextDis = B[u][i].second;
			if (rev_dis[v] > rev_dis[u] + nextDis) {
			 	rev_dis[v] = rev_dis[u] + nextDis;
			 	pq.push({rev_dis[v],v});
	 	 	}
	 	}
	}
	int ret = dis[e];
	for (tuple<int,int,int> t : C) {
		int u = get<0>(t);
		int v = get<1>(t);
		int uv = get<2>(t);
		if (dis[u] != INT32_MAX && rev_dis[v] != INT32_MAX) {
		 	int stoe = dis[u] + uv + rev_dis[v];
		 	ret = min(ret, stoe);
		}
		if (dis[v] != INT32_MAX && rev_dis[u] != INT32_MAX) {
		 	int etos = dis[v] + uv + rev_dis[u];
		 	ret = min(ret, etos);
		}
	}
	if (ret == INT32_MAX) {
	 	cout << -1 << endl;
	} else {
	 	cout << ret << endl;
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

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}
