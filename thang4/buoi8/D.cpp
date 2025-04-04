/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 04.04.2025 20:35:57
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e6+10;
int n, m;
int root[N], min_val[N], max_val[N], numb[N];;
vector<pair<int,int>> A;

int findRoot(int u) {
 	if (root[u] == u) return u;
 	return root[u] = findRoot(root[u]);
}

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
	 	root[i] = i;
	 	numb[i] = 1;
	 	min_val[i] = i;
	 	max_val[i] = i;
	}
	for (int i = 1; i <= m; i++) {
	 	string str;
	 	cin >> str;
	 	if (str == "union") {
	 	 	int u, v;
	 	 	cin >> u >> v;
	 	 	int rootu = findRoot(u);
	 	 	int rootv = findRoot(v);
	 	 	if (rootu != rootv) {
	 	 	 	if (numb[rootu] < numb[rootv]) {
	 	 	 	 	swap(rootu, rootv);
	 	 	 	}
	 	 	 	root[rootv] = rootu;
	 	 	 	numb[rootu] += numb[rootv];
				min_val[rootu] = min(min_val[rootu], min_val[rootv]);
				max_val[rootu] = max(max_val[rootu], max_val[rootv]);
	 	 	}
	 	} else {
	 	 	int u;
	 	 	cin >> u;
	 	 	int rootu = findRoot(u);
	 	 	cout << min_val[rootu] << ' ' << max_val[rootu] << ' ' << numb[rootu] << endl;
	 	}
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
