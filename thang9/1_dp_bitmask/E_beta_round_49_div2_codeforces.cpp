/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-11 22:29:11 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int max_mask = (1 << 10) + 10;
int n, m, k;
vector<int> adj[20];
int dp[max_mask+10][max_mask+10];

void solve(void) {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
	 	int u, v;
	 	cin >> u >> v;
	 	u--;
	 	v--;
	 	adj[u].push_back(v);
	 	adj[v].push_back(u);
	 	dp[(1<<u)+(1<<v)][(1<<v)+(1<<u)] = 1;
	}
	for (int mask = 0; mask < (1 << n); mask++) {
		int cnt = __builtin_popcount(mask);
		if (cnt <= 2) continue;
	 	for (int submask = mask; submask > 0; submask = (submask-1) & mask) {
			int deadEnd = -1;
			for (int i = 0; i < n; i++) {
			    if (submask & (1 << i)) {
			     	deadEnd = i;
			     	break;
			    }
			}
			for (int i = 0; i < adj[deadEnd].size(); i++) {
			    int v = adj[deadEnd][i];
			    if ((mask & (1 << v)) && !(submask & (1 << v))) {
			     	dp[mask][submask] += dp[mask-(1<<deadEnd)][submask-(1<<deadEnd)] + dp[mask-(1<<deadEnd)][submask-(1<<deadEnd)+(1<<v)];
			    }
			}	
	 	}
	}
	int ret = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
	 	int cnt = __builtin_popcount(mask);
	 	if (cnt == k) ret += dp[(1<<n)-1][mask];
   	}
   	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

