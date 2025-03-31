/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 30.03.2025 20:10:55
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m;
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
int moveX[8] = {-1,-1,-1,0,0,1,1,1};
int moveY[8] = {-1,0,1,-1,1,-1,0,1};

void solve(void) {
	cin >> n >> m;
	if (n == 0 && m == 0) exit(0);
	vector<vector<char>> A(n+1,vector<char>(m+1));
	vector<vector<int>> dis(n+1,vector<int>(m+1,INT32_MAX));
	while (!pq.empty()) pq.pop();
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	cin >> A[i][j];
	 	}
	}
	for (int i = 1; i <= n; i++) {
	 	if (A[i][1] == '.') {
	 	 	pq.push({1,{i,1}});
	 	 	dis[i][1] = 1;
	 	} else if (A[i][1] == '#') {
	 	 	pq.push({0,{i,1}});
	 	 	dis[i][1] = 0;
	 	}
	}
	for (int j = 1; j <= m; j++) {
	 	if (A[n][j] == '.') {
	 	 	pq.push({1,{n,j}});
	 	 	dis[n][j] = 1;
	 	} else if (A[n][j] == '#') {
	 	 	pq.push({0,{n,j}});
	 	 	dis[n][j] = 0;
	 	}
	}
	while (!pq.empty()) {
	 	pair<int,pair<int,int>> temp = pq.top();
	 	pq.pop();
	 	int distance = temp.first;
	 	int x = temp.second.first;
	 	int y = temp.second.second;
	 	if (x == 1 || y == m) {
	 	 	cout << distance << endl;
	 	 	return;
	 	}
		if (distance > dis[x][y]) continue;
		for (int i = 0; i < 8; i++) {
		 	int ver = x + moveX[i];
		 	int hor = y + moveY[i];
		 	if (ver < 1 || ver > n || hor < 1 || hor > m) continue;
		 	if (A[ver][hor] == '@') continue;
		 	int isWall = (int)(A[ver][hor] != '#');
		 	if (dis[ver][hor] > dis[x][y] + isWall) {
		 	 	dis[ver][hor] = dis[x][y] + isWall;
		 	 	pq.push({dis[ver][hor], {ver,hor}});
		 	}
		}
	}
	cout << -1 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	while (1) {
	 	solve();
	}

	return 0;
}
