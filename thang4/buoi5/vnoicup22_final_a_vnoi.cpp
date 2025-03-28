/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 28.03.2025 19:11:04
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 5e5+10;
vector<int> A[N];
priority_queue<pair<int,int>> pq;
queue<int> q;
int n, m, k;
bool isWhiteNode[N];
int rDis[N], dis[N];
set<int> ret;

void solve(void) {
	cin >> n >> m >> k;
	memset(rDis,-1,sizeof(rDis));
	memset(dis,-1,sizeof(dis));
	for (int i = 1; i <= m; i++) {
	 	int a, b;
	 	cin >> a >> b;
	 	A[a].push_back(b);
	 	A[b].push_back(a);
	}
	for (int i = 1; i <= k; i++) {
	 	int c, d;
	 	cin >> c >> d;
	 	isWhiteNode[c] = true;
	 	rDis[c] = d;
	 	if (d > 1) {
	 	 	pq.push({d-1,c});
	 	} else if (d == 0) {
			ret.insert(c);
	 	}
	}
	while (!pq.empty()) {
	 	auto [distance,u] = pq.top();
	 	pq.pop();
	 	for (int i = 0; i < A[u].size(); i++) {
	 	 	int v = A[u][i];
	 	 	if (!isWhiteNode[v]) {
	 	 	 	isWhiteNode[v] = true;
	 	 	 	if (distance > 1) {
	 	 	 	 	pq.push({distance-1,v});
	 	 	 	}
	 	 	}
	 	}
	}
	for (int i = 1; i <= n; i++) {
	 	if (isWhiteNode[i]) continue;
	 	dis[i] = 0;
	 	ret.insert(i);
	}
	for (int u : ret) {
		dis[u] = 0;
		q.push(u);	 	
	}
	while (!q.empty()) {
	 	int u = q.front();
	 	q.pop();
	 	for (int i = 0; i < A[u].size(); i++) {
	 	 	int v = A[u][i];
	 	 	if (dis[v] == -1) {
	 	 	 	dis[v] = dis[u] + 1;
	 	 	 	q.push(v);
	 	 	}
	 	}
	}
	for (int i = 1; i <= n; i++) {
	 	if (rDis[i] != -1 && rDis[i] != dis[i]) {
			cout << "NO" << endl;
			return;
	 	}	
	}
	cout << "YES" << endl;
	cout << ret.size() << endl;
	for (int r : ret) cout << r << ' ';
	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
