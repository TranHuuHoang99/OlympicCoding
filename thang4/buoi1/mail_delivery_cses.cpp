/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 04.03.2025 20:31:58
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
set<int> A[N];
int n, m;
vector<int> ret;

void dfs(int cur) {
	while (!A[cur].empty()) {
	 	int temp = *A[cur].begin();
	 	A[cur].erase(A[cur].find(temp));
	 	A[temp].erase(A[temp].find(cur));
	 	dfs(temp);
	}
	ret.push_back(cur);
}

void solve(void) {
 	cin >> n >> m;
 	for (int i = 1; i <= m; i++) {
 	 	int a, b;
 	 	cin >> a >> b;
 	 	A[a].insert(b);
 	 	A[b].insert(a);
 	}
 	for (int i = 1; i <= n; i++) {
 	 	int temp = A[i].size();
 	 	if (temp & 1) {
 	 	 	cout << "IMPOSSIBLE" << endl;
 	 	 	return;
 	 	}
 	}
 	dfs(1);
 	if (ret.size() == m+1) {
 	 	for (int i = 0; i < ret.size(); i++) cout << ret[i] << ' ';
 	 	cout << endl;
 	} else {
 	 	cout << "IMPOSSIBLE" << endl;
    }             
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
