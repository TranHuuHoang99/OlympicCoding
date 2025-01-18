/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 20.01.2025 19:40:14
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 210;
const ll M = 400;
const ll oo = 1e7+10;
int A[N][N];
int n, m;
int dp[M][N][N];

int value(int x1, int y1, int x2, int y2) {
 	if (x1 == x2 && y1 == y2) return A[y1][x1];
 	return A[y1][x1] + A[y2][x2];
}

bool valid(int x1, int y1, int x2, int y2) {
 	if (x1 != x2 || y1 != y2) return true;
 	if (x1 == x2 && x1 == m && y1 == y2 && y1 == n) return true;
 	return false;
}

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	cin >> A[i][j];
	 	}
	}
	int moves = n+m-2;
	for (int i = 0; i <= moves; i++) {
	 	for (int j = 1; j <= n; j++) {
	 	 	for (int k = 0; k <= n; k++) {
	 	 	 	dp[i][j][k] = -oo;
	 	 	}
	 	}
	}
	dp[0][1][1] = 0;
	for (int i = 0; i < moves; i++) {
		for (int y1 = 1; y1 <= n; y1++) {
		 	for (int y2 = y1; y2 <= n; y2++) {
		 	 	int x1 = i+2 - y1;
		 	 	int x2 = i+2 - y2;
		 	 	if (x1 < 0 || x2 < 0) continue;
		 	 	// player 1 move right and player 2 move right
		 	 	if (valid(x1+1, y1, x2+1, y2)) {
		 	 	 	dp[i+1][y1][y2] = max(dp[i+1][y1][y2], dp[i][y1][y2] + value(x1+1,y1,x2+1,y2));
		 	 	}
		 	 	// player 1 move down and player 2 move right
		 	 	if (y1+1 <= y2) {
		 	 	 	if (valid(x1, y1+1, x2+1, y2)) {
		 	 	 	 	dp[i+1][y1+1][y2] = max(dp[i+1][y1+1][y2], dp[i][y1][y2] + value(x1, y1+1, x2+1, y2));	
		 	 	 	}
		 	 	}
		 	 	if (y2+1 <= n) {
		 	 	 	// player 1 move right and player 2 move down
		 	 	 	if (valid(x1+1, y1, x2, y2+1)) {
		 	 	 	 	dp[i+1][y1][y2+1] = max(dp[i+1][y1][y2+1], dp[i][y1][y2] + value(x1+1, y1, x2, y2+1));
		 	 	 	}
		 	 	 	// player 1 move down and player 2 move down
		 	 	 	if (valid(x1, y1+1, x2, y2+1)) {
		 	 	 	 	dp[i+1][y1+1][y2+1] = max(dp[i+1][y1+1][y2+1], dp[i][y1][y2] + value(x1, y1+1, x2, y2+1));
		 	 	 	}
		 	 	}
		 	}
		}
	}
	cout << dp[moves][n][n] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
