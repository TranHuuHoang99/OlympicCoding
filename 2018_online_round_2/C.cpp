#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MAX = 1e3;
const ll N = 1e3+10;
int n, R[N], C[N];
int root[N];
bool visited[N];
int in[N], out[N];
int cnt = 0;

int findRoot(int u) {
 	if (u == root[u]) return u;
 	return root[u] = findRoot(root[u]);
}

void unite(int u, int v) {
 	int rootu = findRoot(u);
 	int rootv = findRoot(v);
 	if (rootu != rootv) {
 	 	root[rootu] = rootv;
 	}
}

void solve(void) {
 	cin >> n;
 	for (int i = 1; i <= n; i++) {
 	 	cin >> R[i] >> C[i];
 	}
 	for (int i = 1; i <= MAX; i++) root[i] = i;
 	for (int i = 1; i <= n; i++) {
 	 	int u = R[i], v = C[i];
 	 	visited[u] = visited[v] = true;
 	 	unite(u, v);
 	 	in[u]++;
 	 	out[v]++;
 	 	int rootBase = findRoot(R[1]);
 	 	bool isConnected = true;
 	 	int numbIn = 0, numbOut = 0;
 	 	int startVal = -1, endVal = -1;
 	 	for (int j = 1; j <= MAX; j++) {
			if (visited[j] == true) {
			 	int temp = findRoot(j);
			 	if (temp != rootBase) {
			 	 	isConnected = false;
			 	 	break;
			 	}
			 	int diff = in[j] - out[j];
				if (diff == 1) {
				 	startVal = j;
				 	numbIn++;
				} else if (diff == -1) {
				 	endVal = j;
				 	numbOut++;
				} else if (diff == 0) {
				 	continue;
				} else {
				 	isConnected = false;
				 	break;
				}
			}
 	 	}
 	 	int ret = 0;
 	 	if (isConnected && numbIn == numbOut && numbIn <= 1) { // numbIn <= 1 or numbOut <= 1 are both same because we check numbIn equal numbOut
 			if (numbIn == 1) {
 			 	ret = startVal * endVal;
	 	 	} else {
	 	 	 	for (int j = 1; j <= MAX; j++) {
	 	 	 	 	if (visited[j]) ret = max(ret, j);
	 	 	 	}
	 	 	 	ret = ret * ret;
	 	 	}
 	 	}
 	 	cout << ret << endl;
 	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

