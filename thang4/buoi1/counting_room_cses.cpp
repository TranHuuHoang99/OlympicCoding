/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 04.03.2025 20:17:15
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+10;
char A[N][N];
int n, m;
vector<pair<int,int>> s;
bool V[N][N];
int step[5] = {1,0,-1,0,1};

void dfs(pair<int,int> next) {
 	int x = next.first, y = next.second;
 	V[x][y] = true;
 	for (int i = 0; i < 4; i++) {
 	 	int ver = x + step[i];
 	 	int hor = y + step[i+1];
 	 	if (ver < 1 || ver > n || hor < 1 || hor > m || V[ver][hor] || A[ver][hor] == '#') continue;
 	 	dfs({ver,hor});
 	}
}

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	cin >> A[i][j];
	 	 	if (A[i][j] == '.') s.push_back({i,j});
	 	}
	}
	int ret = 0;
	for (int i = 0; i < s.size(); i++) {
		if (!V[s[i].first][s[i].second]) {
		 	dfs(s[i]);
		 	ret++;
	 	}
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
