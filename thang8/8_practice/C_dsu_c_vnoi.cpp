/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-07 21:39:35 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
int root[N];
int more_cows[N];
int numb_cows[N];
vector<int> listCows[N]; // using merge small to large algorithm O(logN);
int n, k;

int findRoot(int u) {
 	if (root[u] == u) return u;
 	return root[u] = findRoot(root[u]);
}

void solve(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
	    root[i] = i;
	    listCows[i].push_back(i);
	}	
	for (int i = 1; i <= k; i++) {
	 	string type;
	 	cin >> type;
	 	if (type == "join") {
	 	 	int u, v;
	 	 	cin >> u >> v;
	 	 	int rootU = findRoot(u);
	 	 	int rootV = findRoot(v);
	 	 	if (rootU != rootV) {
	 	 	    // using merge small to large here
	 	 	    if (listCows[rootU].size() < listCows[rootV].size()) {
	 	 	     	swap(rootU, rootV);
	 	 	    }
	 	 	    for (int i = 0; i < listCows[rootV].size(); i++) {
	 	 	     	int cow = listCows[rootV][i];
	 	 	     	// store total number of cows in small cage
	 	 	     	numb_cows[cow] += more_cows[rootV];
	 	 	     	// remove total number of cows in the large cage
	 	 	     	numb_cows[cow] -= more_cows[rootU];
	 	 	     	listCows[rootU].push_back(cow);
	 	 	    }
	 	 	    listCows[rootV].clear();
	 	 	    root[rootV] = rootU;
	 	 	}	
	 	} else if (type == "add") {
	 	 	int u, val;
	 	 	cin >> u >> val;
	 	 	int rootU = findRoot(u);
	 	 	more_cows[rootU] += val;
	 	} else {
	 	 	int u;
	 	 	cin >> u;
	 	 	int rootU = findRoot(u);
	 	 	cout << numb_cows[u] + more_cows[rootU] << endl;
	 	}
	}
}	

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

