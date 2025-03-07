/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 07.03.2025 21:08:12
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

char A[31][31];
set<int> arr[30];
int state[30];
int r, c;
stack<char> st;
bool valid = true;

void dfs(int u) {
 	state[u] = 1;
 	for (int v : arr[u]) {
 	 	if (state[v] == 0) {
 	 	 	dfs(v);
 	 	 	if (!valid) return;
 	 	} else if (state[v] == 1) {
 	 	 	valid = false;
 	 	 	return;
 	 	}
 	}
 	if (!valid) return;
 	st.push(char(u+'A'));
 	state[u] = 2;
}

void solve(void) {
	cin >> r >> c;
	map<char,vector<pair<int,int>>> mp;
	valid = true;
	while (!st.empty()) st.pop();
	memset(state,0,sizeof(state));
	for (int i = 1; i <= r; i++) {
	 	for (int j = 1; j <= c; j++) {
	 	 	cin >> A[i][j];
	 	 	mp[A[i][j]].push_back({i,j});
	 	}
	}
	for (int i = 0; i < 30; i++) {
	 	arr[i].clear();
	}
	vector<int> temp;
	for (auto _mp : mp) {
	 	char name = _mp.first;
	 	temp.push_back(int(name-'A'));
	 	int u = int(name-'A');
	 	vector<pair<int,int>> adj = _mp.second;
	 	for (int i = 0; i < adj.size(); i++) {
			int x = adj[i].first;
			int y = adj[i].second;
			if (x-1 >= 1) {
				if (A[x-1][y] != name) {
				 	int v = int(A[x-1][y]-'A');
				 	arr[u].insert(v);
				}
			}
	 	}
	}
	for (int i = 0; i < temp.size(); i++) {
	 	if (state[temp[i]] == 0) {
	 		dfs(temp[i]);
	 	 	if (!valid) {
	 	 	 	cout << -1 << endl;
	 	 	 	return;
	 	 	}
	 	}
	}
	while (!st.empty()) {
	 	cout << st.top();
	 	st.pop();
	}
	cout << endl;
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
		cout << "Case #" << i << ": ";
	 	solve();
	}

	return 0;
}
