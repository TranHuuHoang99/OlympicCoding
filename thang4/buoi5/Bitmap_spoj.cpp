/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 25.03.2025 21:34:05
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

char A[190][190];
int n, m;
int dis[190][190];
vector<pair<int,int>> one;
int moves[5] = {1,0,-1,0,1};

void solve(void) {
	memset(dis,-1,sizeof(dis));
	one.clear();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	cin >> A[i][j];
	 	 	if (A[i][j] == '1') one.push_back({i,j});
	 	}
	}
	queue<pair<int,int>> q;
	for (pair<int,int> s : one) {
	 	q.push(s);
	 	dis[s.first][s.second] = 0;
	 	while (!q.empty()) {
	 	 	auto [x,y] = q.front();
	 	 	q.pop();
	 	 	for (int i = 0; i < 4; i++) {
	 	 	 	int ver = x + moves[i];
	 	 	 	int hor = y + moves[i+1];
	 	 	 	if (ver < 1 || ver > n || hor < 1 || hor > m || A[ver][hor] == '1') continue;
	 	 	 	if (dis[ver][hor] == -1 || dis[ver][hor] > dis[x][y] + 1) {
	 	 	 	 	dis[ver][hor] = dis[x][y] + 1;
	 	 	 	 	q.push({ver,hor});
	 	 	 	}
	 	 	}
	 	}
	}
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	cout << dis[i][j] << ' ';
	 	}
	 	cout << endl;
	}
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
