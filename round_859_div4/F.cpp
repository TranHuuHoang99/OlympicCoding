/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-04 20:19:42 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, i1, j1, i2, j2;
string str;
void solve(void) {
	cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> str;
	int type = 0;
	if (str[0] == 'U') {
		type = 1 + (str[1] == 'R' ? 2 : 0);
	} else {
	 	type = 0 + (str[1] == 'R' ? 2 : 0);
	}
	vector<vector<vector<bool>>> visited(n+1, vector<vector<bool>>(m+1, vector<bool>(4, false)));
	int x = i1;
	int y = j1;
	int ret = 0;
	while (!visited[x][y][type]) {
	 	if (x == i2 && y == j2) {
	 	 	cout << ret << endl;
	 	 	return;
	 	}
	 	int bounce = 0;
	 	if (type % 2 == 1 && x == 1) {
	 	 	type -= 1;
	 	 	bounce++;
	 	}
	 	if (type % 2 == 0 && x == n) {
	 	 	type += 1;
	 	 	bounce++;
	 	}
	 	if (type >= 2 && y == m) {
	 	 	type -= 2;
	 	 	bounce++;
	 	}
	 	if (type < 2 && y == 1) {
	 	 	type += 2;
	 	 	bounce++;
	 	}
	 	ret += min(1, bounce);
		if (visited[x][y][type]) break;
		visited[x][y][type] = true;
		if (type % 2 == 0) {
		 	x += 1;
		} else {
		 	x -= 1;
		}
		if (type >= 2) {
		 	y += 1;
		} else {
		 	y -= 1;
		}
	}
	cout << -1 << endl;
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



