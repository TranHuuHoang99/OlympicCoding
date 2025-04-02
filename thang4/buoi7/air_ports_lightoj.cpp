/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 02.04.2025 14:45:46
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e4+10;
int n, m;
ll airportCost;
map<ll,vector<pair<int,int>>> mp;
int root[N];

int findRoot(int u) {
 	if (u == root[u]) return u;
 	return root[u] = findRoot(root[u]);
}

void solve(void) {
	memset(root,0,sizeof(root));
	mp.clear();
	cin >> n >> m >> airportCost;
	for (int i = 1; i <= n; i++) root[i] = i;
	for (int i = 1; i <= m; i++) {
	 	int a, b;
	 	ll c;
	 	cin >> a >> b >> c;
	 	mp[c].push_back({a,b});
	}
	ll ret = 1ll * n * airportCost;
	ll numbAirport = n;
	for (auto it : mp) {
	 	ll cost = it.first;
	 	if (cost >= airportCost) continue;
	 	for (pair<int,int> p : it.second) {
	 	 	auto [u,v] = p;
	 	 	int rootu = findRoot(u);
	 	 	int rootv = findRoot(v);
	 	 	if (rootu != rootv) {
				numbAirport--;
				root[rootu] = rootv;
				ret -= airportCost;
				ret += cost;
	 	 	}
	 	}
	}
	cout << ret << ' ' << numbAirport << endl;
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
		cout << "Case " << i << ": ";
	 	solve();
	}

	return 0;
}
