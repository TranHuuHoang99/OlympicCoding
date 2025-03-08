/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 08.03.2025 13:18:13
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

char A[30][30];
int n, m;
int moves[5] = {1,0,-1,0,1};
bool visited[30][30][12];

void dfs(pair<int,int> cur, int toxic) {
 	auto [x,y] = cur;
 	visited[x][y][toxic] = true;
 	for (int i = 0; i < 4; i++) {
 	 	int ver = x + moves[i];
 	 	int hor = y + moves[i+1];
 	 	if (ver < 1 || ver > n || hor < 1 || hor > m || A[ver][hor] == '#') continue;
 	 	int nextToxic = toxic;
 	 	if ('1' <= A[ver][hor] && A[ver][hor] <= '9') nextToxic += int(A[ver][hor]-'0');
 	 	if (A[ver][hor] == 'S') nextToxic = 0;
 	 	if (nextToxic >= 10) continue;
 	 	if (!visited[ver][hor][nextToxic]) dfs({ver,hor}, nextToxic);
 	}
}

void solve(void) {
 	cin >> n >> m;
 	for (int i = 1; i <= n; i++) {
 	 	for (int j = 1; j <= m; j++) {
 	 	 	cin >> A[i][j];
 	 	}
 	}
 	memset(visited, false, sizeof(visited));
 	dfs({1,1},0);
 	bool ret = false;
 	for (int i = 0; i < 10; i++) {
 	 	if (visited[n][m][i]) {
 	 	 	ret = true;
 	 	 	break;
 	 	}
 	}
 	if (ret) {
 	 	cout << "possible" << endl;
 	} else {
 	 	cout << "impossible" << endl;
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
