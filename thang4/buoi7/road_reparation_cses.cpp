/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 01.04.2025 23:21:27
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int n, m;
int root[N];
map<ll,vector<pair<int,int>>> mp;

int findRoot(int u) {
 	if (u == root[u]) return u;
 	return root[u] = findRoot(root[u]);
}

void solve(void) {
 	cin >> n >> m;
 	for (int i = 1; i <= n; i++) root[i] = i;
 	for (int i = 1; i <= m; i++) {
 	 	int a, b;
 	 	ll c;
 	 	cin >> a >> b >> c;
 	 	mp[c].push_back({a,b});
 	}
 	ll ret = 0;
 	int cnt = 0;
 	for (auto it : mp) {
 	 	ll cost = it.first;
 	 	for (pair<int,int> p : it.second) {
 	 	 	auto [u,v] = p;
 	 	 	int rootU = findRoot(u);
 	 	 	int rootV = findRoot(v);
 	 	 	if (rootU != rootV) {
 	 	 		ret += cost;
				cnt++;
				root[rootU] = rootV; 	 	 	 	
 	 	 	}
 	 	}
 	}
 	if (cnt < n-1) {
 	 	cout << "IMPOSSIBLE" << endl;
 	 	return;
 	}
 	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
