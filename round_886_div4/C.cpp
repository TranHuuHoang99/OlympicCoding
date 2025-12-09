/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-09 20:04:03 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

char A[9][9];
void solve(void) {
	pair<int,int> pos = {0,0};
	for (int i = 1; i <= 8; i++) {
	 	for (int j = 1; j <= 8; j++) {
	 	 	cin >> A[i][j];
	 	 	if (pos.first == 0 && pos.second == 0) {
	 	 	 	if (A[i][j] != '.') {
	 	 	 	 	pos = {i,j};
	 	 	 	}
	 	 	}
	 	}
	}
	string ret = "";
	int x = pos.first;
	int y = pos.second;
	while (x <= 8 && A[x][y] != '.') {
		ret += A[x][y];
		x++;
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}

