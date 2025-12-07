/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-07 20:22:08 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e3+10;
int n, m;
int A[N][N];
bool visited[N][N];
int moves[5] = {1,0,-1,0,1};
void solve(void) {
	cin >> n >> m;
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	cin >> A[i][j];
	 	}
	}
	queue<pair<int,int>> q;
	int ret = 0;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
			if (visited[i][j] || A[i][j] == 0) continue;
			q.push({i,j});
			visited[i][j] = true;
			int cnt = 0;
			while (!q.empty()) {
			 	auto [x,y] = q.front();
			 	q.pop();
			 	cnt += A[x][y];
			 	for (int idx = 0; idx < 4; idx++) {
			 	 	int ver = x + moves[idx];
			 	 	int hor = y + moves[idx+1];
			 	 	if (ver < 1 || ver > n || hor < 1 || hor > m || visited[ver][hor] || A[ver][hor] == 0) continue;
			 	 	q.push({ver,hor});
			 	 	visited[ver][hor] = true;
			 	}
			}
			ret = max(ret, cnt);
	 	}
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

