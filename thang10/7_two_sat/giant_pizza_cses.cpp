/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-03 20:23:51 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const ll N = 1e5+10;
int n, m;
vector<int> adj[N*2+10];
// strongly connected components
int timeDfs;
int numb[N*2+10], low[N*2+10];
bool deleted[N*2+10];
stack<int> store;
int root[N*2+10];
// end
vector<int> listGroup[N*2+10];
vector<int> adjGroup[N*2+10];
set<int> masterGroup;
vector<int> topo;
bool visited[N*2+10];
int stateGroup[N*2+10];
int state[N*2+10];
 
void dfs(int u) {
 	timeDfs++;
 	numb[u] = low[u] = timeDfs;
 	store.push(u);
 	for (int v : adj[u]) {
		if (deleted[v] == true) continue;
		if (numb[v] == 0) {
		 	dfs(v);
		 	low[u] = min(low[u], low[v]);
		} else {
		 	low[u] = min(low[u], numb[v]);
		}
 	}
 	if (numb[u] == low[u]) {
 	 	while (!store.empty()) {
 	 	 	int temp = store.top();
 	 	 	store.pop();
 	 	 	deleted[temp] = true;
 	 	 	root[temp] = u;
 	 	 	listGroup[u].push_back(temp);
 	 	 	if (temp == u) break;
 	 	}
 	}
}
 
void dfsTopo(int master) {
	visited[master] = true;
	for (int v : adjGroup[master]) {
	 	if (visited[v] == true) continue;
	 	dfsTopo(v);
	}
	topo.push_back(master);
}
 
void dfsState(int master, int curState) {
	stateGroup[master] = curState;
	for (int v : listGroup[master]) {
	 	state[v] = curState;
	 	int oppV = N*2-v;
	 	if (stateGroup[root[v]] == stateGroup[root[oppV]]) {
	 	 	cout << "IMPOSSIBLE" << endl;
	 	 	exit(0);
	 	}
	 	if (stateGroup[root[oppV]] == 0) {
	 	 	dfsState(root[oppV], 3 - curState); // loai bo nhung canh doi voi v
	 	}
	}
}
 
void solve(void) {
 	cin >> n >> m;
 	for (int u = N-m; u <= N+m; u++) {
 	 	deleted[u] = false;
 	 	visited[u] = false;
 	}
 	for (int i = 1; i <= n; i++) {
 	 	char c1, c2;
 	 	int u, v;
 	 	cin >> c1 >> u >> c2 >> v;
 	 	if (c1 == '-') {
 	 	 	u = -u;
 	 	}
 	 	if (c2 == '-') {
 	 	 	v = -v;
 	 	}
 	 	adj[N-u].push_back(N+v);
 	 	adj[N-v].push_back(N+u);
 	}
 	for (int i = N-m; i <= N+m; i++) {
 		if (i == N || numb[i] != 0) continue;
 		dfs(i);
   	}
	for (int i = 1; i <= m; i++) {
		int u = N-i;
		int oppU = N+i;
		if (root[u] == root[oppU]) {
		 	cout << "IMPOSSIBLE" << endl;
		 	return;
		}
	}
	for (int u = N-m; u <= N+m; u++) {
	 	if (u == N) continue;
	 	int rootu = root[u];
	 	masterGroup.insert(rootu);
	 	for (int v : adj[u]) {
	 	 	int rootv = root[v];
	 	 	if (rootu != rootv) {
				adjGroup[rootu].push_back(rootv);
	 	 	}
	 	}
	}
	for (int master : masterGroup) {
	 	if (visited[master] == true) continue;
	 	dfsTopo(master);
	}
	for (int master : topo) {
	 	if (stateGroup[master] != 0) continue;
	 	dfsState(master, 1);
	}
	for (int i = 1; i <= m; i++) {
	 	if (state[N+i] == 1) {
	 	 	cout << '+' << ' ';
	 	} else {
	 	 	cout << '-' << ' ';
	 	}
	}
	cout << endl;
}
 
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
