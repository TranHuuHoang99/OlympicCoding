/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 21.01.2025 20:19:07
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+10;
const ll M = 50+1;
int n, p, k;
int r, s;
int A[N], B[N];
int dp[N][N][M][M];

void solve(void) {
	cin >> n >> p >> k;
	cin >> r;
	for (int i = 0; i <= n; i++) {
	 	A[i] = 0;
	 	B[i] = 0;
	}
	for (int i = 1; i <= r; i++) {
	 	int temp;
	 	cin >> temp;
	 	A[temp] = 1;
	}
	cin >> s;
	for (int i = 1; i <= s; i++) {
	 	int temp;
	 	cin >> temp;
	 	B[temp] = 1;
	}
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= p; j++) {
	 		for (int a = 0; a <= k; a++) {
	 		 	for (int b = 0; b <= k; b++) {
	 		 	 	dp[i][j][a][b] = -1;
	 		 	}
	 		}
	 	}
	}
	dp[0][0][0][0] = 0;
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= p; j++) {
	 	 	for (int a = 0; a <= k; a++) {
	 	 	 	for (int b = 0; b <= k; b++) {
	 	 	 	 	if (dp[i][j][a][b] == -1) continue;
	 	 	 	 	dp[i+1][j+1][a+1][b] = max(dp[i+1][j+1][a+1][b], dp[i][j][a][b] + 
	 	 	 	}
	 	 	}
	 	}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
