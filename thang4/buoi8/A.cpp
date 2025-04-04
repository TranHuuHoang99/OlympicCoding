/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 04.04.2025 19:32:58
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

char A[110][110];
bool V[110][110];
int cnt[110][110];
pair<int,int> B, C;
int n, m;
queue<pair<int,int>> q;
int moves[5] = {1,0,-1,0,1};

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	cin >> A[i][j];
	 	 	if (A[i][j] == 'B') {
	 	 	 	B = {i,j};
	 	 	}
	 	 	if (A[i][j] == 'C') {
	 	 	 	C = {i,j};
	 	 	}
	 	}
	}
	q.push(C);
	V[C.first][C.second] = true;
	while (!q.empty()) {
	 	auto [x,y] = q.front();
	 	q.pop();
		for (int i = 0; i < 4; i++) {
		 	int ver = x + moves[i];
		 	int hor = y + moves[i+1];
		 	if (ver < 1 || ver > n || hor < 1 || hor > m || A[ver][hor] == '*') continue;
		 	if (!V[ver][hor]) {
		 	 	cnt[ver][hor] = cnt[x][y] + 1;
		 	 	V[ver][hor] = true;
		 	 	q.push({ver,hor});
		 	}
		}
	}
	cout << cnt[B.first][B.second] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
