/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-06 15:48:36 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 150;
int n, m;
vector<int> adj[N*2+10];
int timeDfs;
int numb[N*2+10], low[N*2+10];
bool deleted[N*2+10];
stack<int> store;
int root[N*2+10];
vector<int> listGroup[N*2+10];
set<int> masterGroup;
vector<int> adjGroup[N*2+10];
bool visited[N*2+10];
vector<int> topo;
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
 	for (int child : listGroup[master]) {
 	 	state[child] = curState;
 	 	int oppChild = N*2-child;
 	 	if (stateGroup[root[child]] == stateGroup[root[oppChild]]) {
 	 	 	cout << "Impossible" << endl;
 	 	 	exit(0);
 	 	}
 	 	if (stateGroup[root[oppChild]] == 0) {
 	 		dfsState(root[oppChild], 3 - curState);
 	 	}
 	}
}

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
	 	int u, v, status;
	 	cin >> u >> v >> status;
	 	if (status == 1) {
	 	 	adj[N+u].push_back(N+v);
	 	 	adj[N+v].push_back(N+u);
	 	 	adj[N-u].push_back(N-v);
	 	 	adj[N-v].push_back(N-u);
	 	} else {
	 	 	adj[N+u].push_back(N-v);
	 	 	adj[N-v].push_back(N+u);
	 	 	adj[N+v].push_back(N-u);
	 	 	adj[N-u].push_back(N+v);
	 	}
	}
	for (int i = N-n; i <= N+n; i++) {
	 	if (i == N || numb[i] != 0) continue;
	 	dfs(i);
	}
	for (int i = 1; i <= n; i++) {
	 	int u = N-i;
	 	int oppU = N+i;
	 	if (root[u] == root[oppU]) {
	 	 	cout << "Impossible" << endl;
	 	 	return;
	 	}
	}
	for (int u = N-n; u <= N+n; u++) {
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
	vector<int> ret;
	for (int i = 1; i <= n; i++) {
	 	if (state[N+i] == 1) {
	 	 	ret.push_back(i);
	 	}
	}
	cout << ret.size() << endl;
	for (int r : ret) cout << r << ' ';
	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


















































