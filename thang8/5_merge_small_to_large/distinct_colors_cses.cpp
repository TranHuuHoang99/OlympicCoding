/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-07-25 20:54:48 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n;
int A[N];
vector<int> adj[N];
int ans[N];
set<int> save[N];

void dfs(int u, int p) {
	int largest_child = -1;
	int max_val = 0;
	for (int v : adj[u]) {
	 	if (v == p) continue;
	 	dfs(v, u);
	 	if (save[v].size() > max_val) {
	 	    max_val = save[v].size();
	 	    largest_child = v;
	 	}	
	}
	if (largest_child != -1) {
	 	save[u].swap(save[largest_child]);
	}
	for (int v : adj[u]) {
	 	if (v == p || v == largest_child) continue;
	 	for (int color : save[v]) {
	 	 	save[u].insert(color);
	 	}
	}
	save[u].insert(A[u]);
	ans[u] = save[u].size();
}

void solve(void) {
 	cin >> n;
 	for (int i = 1; i <= n; i++) cin >> A[i];
 	for (int i = 1; i <= n-1; i++) {
 	    int u, v;
 	    cin >> u >> v;
 	    adj[u].push_back(v);
 	    adj[v].push_back(u);
 	}
 	dfs(1, 1);
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
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
	solve();
	return 0;
}

