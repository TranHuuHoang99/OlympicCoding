/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-13 15:12:07 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 3e4+10;
int n, m;
int A[12][12];
vector<vector<int>> gen[10];
map<int,int> save;

void solve(void) {
	cin >> n >> m;
	memset(A, 0, sizeof(A));
	for (int i = 1; i <= m; i++) {
	 	int val, u, v;
	 	cin >> val >> u >> v;
	 	A[u][v] += val;
	}
	if (n == 1) {
	 	cout << A[1][1] << ' ' << 1 << endl;
	 	return;
	}
	save.clear();
	for (vector<int> arr : gen[n]) {
		int sum = 0;
	 	for (int i = 0; i < arr.size(); i++) {
	 	 	for (int j = i+1; j < arr.size(); j++) {
				sum += A[arr[i]][arr[j]]; 	 	
	 	 	}
	 	}
	 	save[sum]++;
	}
	auto it = save.end();
	it--;
	pair<int,int> ret = *it;
	cout << ret.first << ' ' << ret.second << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= 9; i++) {
	 	vector<int> arr(i);
	 	iota(arr.begin(), arr.end(), 1);
	 	do {
	 	 	gen[i].push_back(arr);
	 	} while (next_permutation(arr.begin(), arr.end()));
	}
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}

