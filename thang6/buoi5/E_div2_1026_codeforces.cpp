#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
const ll M = 6e5+10;
int V[N], P[N];
map<int,int> volume, pitch;
bool visited[M];
set<int> adj[M];
int n;
vector<int> ret;

void dfs(int u) {
 	visited[u] = true;
 	for (int v : adj[u]) {
 	 	if (visited[v] == false) {
 	 	 	dfs(v);
 	 	}
 	}
}

void eulerPath(int u) {
 	while (!adj[u].empty()) {
 	 	int v = *adj[u].begin();
 		adj[u].erase(v);
 		adj[v].erase(u);
 		eulerPath(v);
 	}
 	ret.push_back(u);
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= 3*n; i++) {
	 	visited[i] = false;
	 	adj[i].clear();
	}
	ret.clear();
	volume.clear();
	pitch.clear();
	vector<int> tempV, tempP;
	for (int i = 1; i <= n; i++) {
		cin >> V[i] >> P[i];
		tempV.push_back(V[i]);
		tempP.push_back(P[i]);	
  	}
  	sort(tempV.begin(), tempV.end());
  	sort(tempP.begin(), tempP.end());
  	for (int i = 0; i < tempV.size(); i++) {
  	 	if (volume.find(tempV[i]) == volume.end()) {
  	 	 	volume[tempV[i]] = int(volume.size()+1);
  	 	}
  	}
  	for (int i = 0; i < tempP.size(); i++) {
  	 	if (pitch.find(tempP[i]) == pitch.end()) {
  	 		pitch[tempP[i]] = int(pitch.size()+1);
  	 	}
  	}
  	for (int i = 1; i <= n; i++) {
  	 	int new_v = volume[V[i]] + n;
  	 	adj[i].insert(new_v);
  	 	adj[new_v].insert(i);
  	 	int new_p = pitch[P[i]] + volume.size() + n;
  	 	adj[i].insert(new_p);
  	 	adj[new_p].insert(i);
  	}
  	dfs(1);
  	bool isValid = true;
  	int totalNode = n + int(volume.size()) + int(pitch.size());
  	for (int i = 1; i <=  totalNode; i++) {
  	 	if (!visited[i]) {
  	 	 	isValid = false;
  	 	 	break;
  	 	}
  	}
  	if (!isValid) {
  	 	cout << "NO" << endl;
  	 	return;
  	}
  	vector<int> oddNode;
  	for (int i = 1; i <= totalNode; i++) {
  	 	if (adj[i].size() % 2 == 1) {
  	 	 	oddNode.push_back(i);
  	 	}
  	}
  	if ((int)oddNode.size() == 1 || (int)oddNode.size() > 2) {                   
  	 	cout << "NO" << endl;
  	 	return;
  	}
  	cout << "YES" << endl;
  	int startNode = (oddNode.empty()) ? 1 : oddNode[0];
  	eulerPath(startNode);
  	for (int i = 1; i <= n; i++) visited[i] = false;
  	for (int i = 0; i < ret.size(); i++) {
  	 	if (ret[i] <= n && visited[ret[i]] == false) {
  	 	 	cout << ret[i] << ' ';
  	 	 	visited[ret[i]] = true;
  	 	}
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
	 	solve();
	}

	return 0;
}

































