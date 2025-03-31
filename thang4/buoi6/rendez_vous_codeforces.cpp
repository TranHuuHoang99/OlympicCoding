/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 29.03.2025 23:11:28
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
int n, m, h;
vector<pair<int,int>> A[N];
priority_queue<pair<ll,pair<int,int>>, vector<pair<ll,pair<int,int>>>, greater<pair<ll,pair<int,int>>>> pq;
bool horse[N];
ll dis[N][2], revDis[N][2];

void reset(void) {
	for (int i = 1; i <= n; i++) {
	 	A[i].clear();
	 	horse[i] = false;
	 	for (int j = 0; j <= 1; j++) {
	 	 	dis[i][j] = LLONG_MAX;
	 	 	revDis[i][j] = LLONG_MAX;
	 	}
	}
}

void djikstra(int start, ll update[N][2]) {
	update[start][0] = 0;
	pq.push({0,{start,0}});
	while (!pq.empty()) {
	 	pair<ll,pair<int,int>> temp = pq.top();
	 	pq.pop();
	 	ll distance = temp.first;
	 	int u = temp.second.first;
	 	int state = temp.second.second;
	 	if (distance > update[u][state]) continue;
	 	for (int i = 0; i < A[u].size(); i++) {
	 	 	int v = A[u][i].first;
	 	 	ll nextDis = A[u][i].second;
	 	 	if (state == 0) {
	 	 	 	if (horse[u]) {
	 	 	 	 	if (update[v][1] > update[u][0] + nextDis/2) {
	 	 	 	 	 	update[v][1] = update[u][0] + nextDis/2;
	 	 	 	 	 	pq.push({update[v][1], {v,1}});
	 	 	 	 	}
	 	 	 	} else {
	 	 	 	 	if (update[v][0] > update[u][0] + nextDis) {
	 	 	 	 	 	update[v][0] = update[u][0] + nextDis;
	 	 	 	 	 	pq.push({update[v][0], {v,0}});
	 	 	 	 	}
	 	 	 	}
	 	 	} else {
				if (update[v][1] > update[u][1] + nextDis/2) {
				 	update[v][1] = update[u][1] + nextDis/2;
				 	pq.push({update[v][1],{v,1}});
				}
	 	 	}	
	 	}
	}
}

void solve(void) {
 	cin >> n >> m >> h;
 	reset();
 	for (int i = 1; i <= h; i++) {
 	 	int temp;
 	 	cin >> temp;
 	 	horse[temp] = true;
 	}
 	for (int i = 1; i <= m; i++) {
 	 	int a, b;
 	 	ll c;
 	 	cin >> a >> b >> c;
 	 	A[a].push_back({b,c});
 	 	A[b].push_back({a,c});
 	}
	djikstra(1,dis);
	djikstra(n,revDis);
	ll ret = min(dis[n][0],dis[n][1]);
	ret = min(ret,min(revDis[1][0],revDis[1][1]));
	for (int i = 2; i < n; i++) {
	 	for (int j = 0; j <= 1; j++) {
	 	 	for (int k = 0; k <= 1; k++) {
	 	 	 	if (dis[i][j] != LLONG_MAX && revDis[i][k] != LLONG_MAX) {
	 	 	 	 	ret = min(ret,max(dis[i][j],revDis[i][k]));
	 	 	 	}
	 	 	}
	 	}
	}
	if (ret == LLONG_MAX) {
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
