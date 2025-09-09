/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-29 21:56:04 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
int n;
ll MOD;
vector<int> adj[N];
ll dp_in[N], dp_out[N];

void dfs_out(int u, int parent) {
 	dp_out[u] = 1ll;
 	for (int v : adj[u]) {
 	 	if (v == parent) continue;
 	 	dfs_out(v, u);
 	 	dp_out[u] = (dp_out[u] % MOD * (dp_out[v] % MOD + 1ll % MOD) % MOD) % MOD;
 	}
}

void dfs_in(int u, int parent) {
 	vector<int> children;
 	for (int v : adj[u]) {
 	 	if (v == parent) continue;
 	 	children.push_back(v);
 	}
 	int len = children.size();
 	vector<ll> prefixMultiple(len+5), suffixMultiple(len+5);
 	prefixMultiple[0] = 1ll;
 	for (int i = 1; i <= len; i++) {
 		int v = children[i-1];
 	 	prefixMultiple[i] = (prefixMultiple[i-1] % MOD * (dp_out[v] % MOD + 1ll % MOD) % MOD) % MOD;
 	}
	suffixMultiple[len+1] = 1ll;
	for (int i = len; i >= 1; i--) {
		int v = children[i-1];
	 	suffixMultiple[i] = (suffixMultiple[i+1] % MOD * (dp_out[v] % MOD + 1ll % MOD) % MOD) % MOD;
	}
	int idx = 0;
	for (int v : adj[u]) {
	 	if (v == parent) continue;
	 	idx++;
	 	ll temp = dp_in[u];
	 	temp = (temp % MOD * prefixMultiple[idx-1] % MOD * suffixMultiple[idx+1] % MOD) % MOD;
	 	temp = (temp % MOD + 1ll % MOD) % MOD;
	 	dp_in[v] = temp;
	 	dfs_in(v, u);
	}
}

void solve(void) {
 	cin >> n >> MOD;
 	for (int i = 1; i <= n-1; i++) {
 	 	int u, v;
 	 	cin >> u >> v;
 	 	adj[u].push_back(v);
 	 	adj[v].push_back(u);
 	}
 	dfs_out(1,1);
 	dp_in[1] = 1ll;
 	dfs_in(1,1);
 	for (int i = 1; i <= n; i++) {
 	 	ll ans = (dp_out[i] % MOD * dp_in[i] % MOD) % MOD;
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

