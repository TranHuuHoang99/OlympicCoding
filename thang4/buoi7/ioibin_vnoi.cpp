/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 01.04.2025 20:17:57
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e4+10;
int p;
int root[N];

int findRoot(int u) {
 	if (u == root[u]) return u;
 	int rootU = findRoot(root[u]);
 	root[u] = rootU;
 	return rootU;
}

void union_set(int u, int v) {
 	int rootU = findRoot(u);
 	int rootV = findRoot(v);
 	if (rootU != rootV) {
 	 	root[rootU] = rootV;
 	}
}

void solve(void) {
 	cin >> p;
 	for (int i = 1; i <= 1e4; i++) root[i] = i;
 	for (int i = 1; i <= p; i++) {
 	 	int a, b, c;
 	 	cin >> a >> b >> c;
 	 	if (c == 2) {
 	 	 	if (findRoot(a) == findRoot(b)) {
 	 	 	 	cout << 1 << endl;
 	 	 	} else {
 	 	 	 	cout << 0 << endl;
 	 	 	}
 	 	} else {
 	 	 	union_set(a,b);
 	 	}
 	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
