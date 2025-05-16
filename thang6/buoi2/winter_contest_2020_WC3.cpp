#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e4+10;
int n, e, m, k;
int root[N];
bool hasData[N];

void init(void) {
 	for (int i = 0; i <= 1e4; i++) {
 	 	hasData[i] = false;
 	 	root[i] = i;
	}
}

bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b) {
 	return a.first < b.first;
}

int findRoot(int u) {
 	if (u == root[u]) return u;
 	return root[u] = findRoot(root[u]);
}

void solve(void) {
	init();
	cin >> n >> e >> m >> k;
	for (int i = 1; i <= k; i++) {
	 	int temp;
	 	cin >> temp;
	 	hasData[temp] = true;
	}
	vector<pair<int,pair<int,int>>> A;
	for (int i = 1; i <= e; i++) {
	 	int a, b, c;
	 	cin >> a >> b >> c;
	 	A.push_back({c,{a,b}});
	}
	sort(A.begin(), A.end(), cmp);
	ll ret = 1ll * (n-k) * m;
	for (int i = 0; i < A.size(); i++) {
		pair<int,pair<int,int>> temp = A[i];
		ll cost = 1ll * temp.first;
		auto [u,v] = temp.second;
		int rootu = findRoot(u);
		int rootv = findRoot(v);
		if (rootu != rootv && (hasData[rootu] == false || hasData[rootv] == false)) {
		 	root[rootu] = rootv;
		 	if (hasData[rootu] == true || hasData[rootv] == true) {
		 	 	hasData[rootu] = true;
		 	 	hasData[rootv] = true;
		 	}
		 	ret += cost;
		}
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

