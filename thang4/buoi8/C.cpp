/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 04.04.2025 19:58:01
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e2+10;
const ll M = 1e4+10;
int dis[N][M];
vector<pair<int,pair<int,int>>> A[N];
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
int k, n, r;

void solve(void) {
 	cin >> k >> n >> r;
 	for (int i = 1; i <= n; i++) {
 	 	for (int j = 0; j <= k; j++) {
 	 	 	dis[i][j] = INT32_MAX;
 	 	}
 	 	A[i].clear();
 	}
 	for (int i = 1; i <= r; i++) {
 	 	int a, b, c, d;
 	 	cin >> a >> b >> c >> d;
 	 	A[a].push_back({b,{c,d}});
 	}
 	dis[1][0] = 0;
 	pq.push({0,{1,0}});
 	while (!pq.empty()) {
 	 	pair<int,pair<int,int>> temp = pq.top();
 	 	pq.pop();
 	 	int distance = temp.first;
 	 	int u = temp.second.first;
 	 	int cost = temp.second.second;
 	 	if (distance > dis[u][cost]) continue;
 	 	for (int i = 0; i < A[u].size(); i++) {
 	 	 	pair<int,pair<int,int>> nextPath = A[u][i];
 	 	 	int v = nextPath.first;
 	 	 	int len = nextPath.second.first;
 	 	 	int nCost = nextPath.second.second;
 	 		if (cost + nCost > k) continue;
 	 		if (dis[v][cost+nCost] > dis[u][cost] + len) {
 	 		 	dis[v][cost+nCost] = dis[u][cost] + len;
 	 		 	pq.push({dis[v][cost+nCost], {v, cost+nCost}});
 	 		}
 	 	}
 	}
 	int ret = INT32_MAX;
 	for (int i = 0; i <= k; i++) ret = min(ret, dis[n][i]);
 	if (ret == INT32_MAX) {
 	 	cout << -1 << endl;
 	 	return;
 	}
 	cout << ret << endl;
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
