/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-26 21:20:54 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
int n, m;
vector<int> adj[N];
int in[N]; // longest path which is not u's children
int out[N]; // longest path which is u's children
vector<int> prefixMax[N]; // prefix max value from children 1 -> n
vector<int> suffixMax[N]; // suffix max value from children n -> 1
vector<int> dp[N]; // number of children path

void dfs1(int u, int parent) {
	out[u] = 0;
	for (int v : adj[u]) {
	 	if (v == parent) continue;
	 	dfs1(v, u);
	 	out[u] = max(out[u], out[v]+1);
	 	dp[u].push_back(out[v]+1);
	}
	prefixMax[u].push_back(0);
	suffixMax[u].push_back(0);
	for (int v : adj[u]) {
	 	if (v == parent) continue;
	 	prefixMax[u].push_back(out[v]+1);
	 	suffixMax[u].push_back(out[v]+1);
	}
	prefixMax[u].push_back(0);
	suffixMax[u].push_back(0);
}

void dfs2(int u, int parent) {
	int idx = 0;
 	for (int v : adj[u]) {
 	 	if (v == parent) continue;
 	 	idx++;
 		in[v] = max(prefixMax[u][idx-1], suffixMax[u][idx+1]) + 1; // get max all path which are children of u not included v
 		in[v] = max(in[v], in[u]+1); // get max the path is the parent of u
 		dfs2(v,u);
 	}
}

void dfs3(int u, int parent) {
 	if (in[u] != -1) {
 		dp[u].push_back(in[u]);
 	}
 	for (int v : adj[u]) {
 	 	if (v == parent) continue;
 	 	dfs3(v, u);
 	}
}

void solve(void) {
 	cin >> n >> m;
 	for (int i = 0; i <= n; i++) {
 	 	out[i] = in[i] = -1;
 	}
 	for (int i = 1; i <= n-1; i++) {
 	 	int u, v;
 	 	cin >> u >> v;
 	 	adj[u].push_back(v);
 	 	adj[v].push_back(u);
 	}
 	dfs1(1,1);
 	for (int u = 1; u <= n; u++) {
 		int len = prefixMax[u].size()-1;
 		for (int i = 1; i < len; i++) {
 		 	prefixMax[u][i] = max(prefixMax[u][i], prefixMax[u][i-1]);
 		}
 		for (int i = len-1; i >= 1; i--) {
 			suffixMax[u][i] = max(suffixMax[u][i], suffixMax[u][i+1]);			
 		}
 	}
 	dfs2(1,1);
 	dfs3(1,1);
 	for (int u = 1; u <= n; u++) {
 	 	sort(dp[u].begin(), dp[u].end());
 	}
 	for (int i = 1; i <= m; i++) {
 	 	int x, t;
 	 	cin >> x >> t;
 	 	int idx = -1;
		int left = 0;
		int right = dp[x].size()-1;
		while (left <= right) {
		 	int mid = (left+right)>>1;
		 	if (dp[x][mid] <= t) {
		 	 	idx = mid;
		 	 	left = mid+1;
		 	} else {
		 	 	right = mid - 1;
		 	}
		}
		int ans = dp[x].size() - (idx+1);
		cout << ans << endl;
 	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}











