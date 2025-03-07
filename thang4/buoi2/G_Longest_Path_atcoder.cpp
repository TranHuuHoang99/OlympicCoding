/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 07.03.2025 20:18:29
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
vector<int> A[N];
int n, m;
int score[N];
bool visited[N];
stack<int> st;

void dfs(int u) {
 	visited[u] = true;
 	for (int i = 0; i < A[u].size(); i++) {
 	 	int v = A[u][i];
 	 	score[v] = max(score[v], score[u]+1);
 	 	if (!visited[v]) {
 	 	 	dfs(v);
 	 	}
	}
	st.push(u);
}

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
	 	int a, b;
	 	cin >> a >> b;
	 	A[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
	 	if (!visited[i]) dfs(i);
	}
	vector<int> temp;
	while (!st.empty()) {
	 	temp.push_back(st.top());
	 	st.pop();
	}
	for (int i = 0; i < temp.size(); i++) {
	 	int u = temp[i];
	 	for (int j = 0; j < A[u].size(); j++) {
	 	 	int v = A[u][j];
	 	 	score[v] = max(score[v], score[u]+1);
	 	}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) ret = max(ret, score[i]);
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
