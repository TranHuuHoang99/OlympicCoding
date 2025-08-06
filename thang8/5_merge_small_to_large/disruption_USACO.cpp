/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-02 23:04:53 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 5e4+10;
int n, m;
vector<pair<int,int>> adj[N];
set<pair<int,int>> save[N];
int ans[N];

void dfs(int u, int p) {
 	for (pair<int,int> next : adj[u]) {
 	 	int v = next.first;
 	 	int id = next.second;
 	 	if (v == p) continue;
 	 	dfs(v, u);
 	 	if (!save[v].empty()) {
 	 	 	pair<int,int> temp = *save[v].begin();
 	 	 	ans[id] = temp.first;
 	 	}
 	 	if (save[v].size() > save[u].size()) {
 	 	 	save[u].swap(save[v]);
 	 	}
 	 	for (pair<int,int> temp : save[v]) {
 	 	 	if (save[u].find(temp) == save[u].end()) {
 	 	 	 	save[u].insert(temp);
 	 	 	} else {
 	 	 	 	save[u].erase(temp);
 	 	 	}
 	 	}
 	 	save[v].clear();
 	}
}

void solve(void) {
 	cin >> n >> m;
 	for (int i = 1; i <= n-1; i++) {
 	 	int u, v;
 	 	cin >> u >> v;
 	 	adj[u].push_back({v,i});
 	 	adj[v].push_back({u,i});
 	 	ans[i] = -1;
 	}
	for (int i = 1; i <= m; i++) {
	 	int u, v, val;
	 	cin >> u >> v >> val;
	 	save[u].insert({val,i});
	 	save[v].insert({val,i});
	}
	dfs(1,1);
	for (int i = 1; i <= n-1; i++) cout << ans[i] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("disrupt.in", "r", stdin);
	freopen("disrupt.out", "w", stdout);	
	solve();
	return 0;
}

