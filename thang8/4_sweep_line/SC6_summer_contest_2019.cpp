/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-07-28 21:31:27 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e3+10;
const ll M = 5e3+10;
int n, m, s, e, k;
vector<int> adj[M];
pair<int,int> password[N];
vector<int> sweep_line;
bool visited[N];

void dfs(int u, int id) {
    visited[u] = true;
   	for (int v : adj[u]) {
     	if (!visited[v] && password[v].first <= id && id <= password[v].second) {
     	 	dfs(v, id);
     	}
    }
}	

void solve(void) {
	cin >> n >> m >> s >> e >> k;
	sweep_line.clear();
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
	    cin >> password[i].first >> password[i].second;
	    sweep_line.push_back(password[i].first-1);
	    sweep_line.push_back(password[i].second);
	}	
	sweep_line.push_back(0);
	sweep_line.push_back(k);
	sort(sweep_line.begin(), sweep_line.end());
	for (int i = 1; i <= m; i++) {
	 	int u, v;
	 	cin >> u >> v;
	 	adj[u].push_back(v);
	}
	int ret = 0;
	for (int i = 0; i < sweep_line.size() - 1; i++) {
	 	if (sweep_line[i]+1 <= sweep_line[i+1]) {
	 	 	for (int j = 1; j <= n; j++) visited[j] = false;
	 	 	dfs(s, sweep_line[i]+1);
	 	}
	 	if (visited[e] == true) {
	 	    ret += sweep_line[i+1]-sweep_line[i];
	 	}	
	}
	cout << ret << endl;
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
	 	solve();
	}
	return 0;
}

