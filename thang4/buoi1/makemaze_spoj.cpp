/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 04.03.2025 19:53:07
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

char A[24][24];
bool V[24][24];
int n, m;
vector<pair<int,int>> path;
int step[5] = {1,0,-1,0,1};

bool dfs(pair<int,int> next) {
 	int x = next.first, y = next.second;
 	V[x][y] = true;
	if (x == path[1].first && y == path[1].second) return true;
	for (int i = 0; i < 4; i++) {
	 	int ver = x + step[i];
	 	int hor = y + step[i+1];
	 	if (ver < 1 || ver > m || hor < 1 || hor > n || A[ver][hor] == '#' || V[ver][hor]) continue;
	 	if (dfs({ver,hor})) return true; 
	}
	return false;
}

void solve(void) {
	cin >> m >> n;
	path.clear();
	for (int i = 1; i <= m; i++) {
	 	for (int j = 1; j <= n; j++) {
	 		cin >> A[i][j];
	 		V[i][j] = false;	
	 		if ((i == 1 || j == 1 || i == m || j == n) && A[i][j] == '.') {
	 		 	path.push_back({i,j});
	 		}
		}
	}
	if (path.size() != 2u) {
	 	cout << "invalid" << endl;
	 	return;
	}
	if (dfs(path[0])) {
	 	cout << "valid" << endl;
	} else {
	 	cout << "invalid" << endl;
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
