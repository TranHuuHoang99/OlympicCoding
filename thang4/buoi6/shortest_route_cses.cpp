/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 28.03.2025 20:02:52
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int n, m;
ll dis[N];
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
vector<pair<int,ll>> A[N];

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
	 	int a, b;
	 	ll c;
	 	cin >> a >> b >> c;
	 	A[a].push_back({b,c});
	}
	for (int i = 1; i <= n; i++) dis[i] = LLONG_MAX;
	dis[1] = 0;
	pq.push({0,1});
	while (!pq.empty()) {
	 	pair<ll,int> temp = pq.top();
	 	pq.pop();
	 	ll distance = temp.first;
	 	int u = temp.second;
	 	if (distance > dis[u]) continue;
	 	for (int i = 0; i < A[u].size(); i++) {
	 	 	int v = A[u][i].first;
	 	 	ll nextDis = A[u][i].second;
	 	 	if (dis[v] > dis[u] + nextDis) {
	 	 	 	dis[v] = dis[u] + nextDis;
	 	 	 	pq.push({dis[v], v});
	 	 	}
	 	}
	}
	for (int i = 1; i <= n; i++) cout << dis[i] << ' ';
	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
