/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-26 19:36:53 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9+7;
const ll N = 1e5+10;
int n;
vector<int> adj[N];
ll dp[N][2];

void dfs(int u, int parent) {
 	dp[u][0] = 1ll;
 	dp[u][1] = 1ll;
 	for (int v : adj[u]) {
 	 	if (v == parent) continue;
 	 	dfs(v, u);
 	 	dp[u][0] = (dp[u][0] % MOD * ((dp[v][1] % MOD + dp[v][0] % MOD) % MOD) % MOD) % MOD;
 	 	dp[u][1] = (dp[u][1] % MOD * dp[v][0] % MOD) % MOD;
 	}
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n-1; i++) {
	 	int u, v;
	 	cin >> u >> v;
	 	adj[u].push_back(v);
	 	adj[v].push_back(u);
	}
	dfs(1,1);
	ll ret = (dp[1][0] % MOD + dp[1][1] % MOD) % MOD;
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

