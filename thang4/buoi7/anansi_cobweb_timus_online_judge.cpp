/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 01.04.2025 21:27:34
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10, M = 1e5+10;
int n, m, q;
int root[N];
pair<int,int> A[M];
bool mark[M];
vector<int> query;

int findRoot(int u) {
 	if (u == root[u]) return u;
 	return root[u] = findRoot(root[u]);
}

void solve(void) {
 	cin >> n >> m;
 	for (int i = 1; i <= n; i++) root[i] = i;
 	for (int i = 1; i <= m; i++) {
 	 	cin >> A[i].first >> A[i].second;
 	}
 	cin >> q;
 	for (int i = 1; i <= q; i++) {
 	 	int temp;
 	 	cin >> temp;
 	 	mark[temp] = true;
 	 	query.push_back(temp);
 	}
 	int cntWeb = n;
 	for (int i = 1; i <= m; i++) {
 	 	if (mark[i]) continue;
		auto [u,v] = A[i];
		int rootU = findRoot(u);
		int rootV = findRoot(v);
		if (rootU != rootV) {
		 	cntWeb--;
		 	root[rootU] = rootV;
		}
 	}
 	vector<int> ret;
 	reverse(query.begin(), query.end());
 	for (int i = 0; i < query.size(); i++) {
 	 	ret.push_back(cntWeb);
 	 	auto [u,v] = A[query[i]];
 	 	int rootU = findRoot(u);
 	 	int rootV = findRoot(v);
 	 	if (rootU != rootV) {
 	 	 	root[rootU] = rootV;
 	 	 	cntWeb--;
 	 	}
 	}
	reverse(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); i++) cout << ret[i] << ' ';
	cout << endl; 	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
