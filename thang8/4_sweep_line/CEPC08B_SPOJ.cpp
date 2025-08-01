/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-07-29 19:33:00 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6+10;
int root[N];
bool isFloat[N];
vector<pair<int,int>> A;
vector<int> B;
int n, d;
int ans[N];
int connected_comp;

bool cmp(pair<int,int> a, pair<int,int> b) {
 	return a.first > b.first;
}

int findRoot(int u) {
 	if (u == root[u]) return u;
 	return root[u] = findRoot(root[u]);
}

void dsu(int u, int v) {
 	int rootU = findRoot(u);
 	int rootV = findRoot(v);
 	if (rootU != rootV) {
 	 	connected_comp--;
 	 	root[u] = rootV;
 	}
}

void solve(void) {
	connected_comp = 0;
 	A.clear();
 	B.clear();
 	cin >> n >> d;
 	A.resize(n);
 	B.push_back(0);
 	B.push_back(1e9);
 	for (int i = 0; i < n; i++) {
 	 	cin >> A[i].first;
 	 	A[i].second = i;
 	 	isFloat[i] = false;
 	 	root[i] = i;
 	 	B.push_back(A[i].first);
 	}
 	sort(A.begin(), A.end(), cmp);
 	sort(B.begin(), B.end());
 	reverse(B.begin(), B.end());
 	vector<int> temp;
 	temp.push_back(B[0]);
 	for (int i = 1; i < B.size(); i++) {
 	 	if (B[i] != B[i-1]) temp.push_back(B[i]);
 	}
 	B = temp;
 	int idx = 0;
 	vector<int> numbComps(B.size(), 0);
 	for (int i = 0; i < B.size(); i++) {
 		numbComps[i] = connected_comp;
		while (idx < n && B[i] == A[idx].first) {
		 	int id = A[idx].second;
		 	isFloat[id] = true;
		 	connected_comp++;
		 	if (id > 0 && isFloat[id-1] == true) {
		 	 	dsu(id, id-1);
		 	}
		 	if (id < n-1 && isFloat[id+1] == true) {
		 	 	dsu(id, id+1);
		 	}
		 	idx++;
		}
 	}
 	reverse(B.begin(), B.end());
 	reverse(numbComps.begin(), numbComps.end());
 	for (int i = 0; i < d; i++) {
 	 	int water_level;
 	 	cin >> water_level;
 	 	int left = 0;
 	 	int right = B.size()-1;
 	 	int idx = 0;
 	 	while (left <= right) {
 	 	 	int mid = (left+right) >> 1;
 	 	 	if (B[mid] <= water_level) {
				idx = mid;
				left = mid + 1; 	 	 	 	
 	 	 	} else {
 	 	 	 	right = mid - 1;
 	 	 	}
 	 	}
 	 	cout << numbComps[idx] << ' ';
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

