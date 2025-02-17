/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 13.02.2025 20:59:28
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 4e3+10;
int n;
int A[4];
int dp[N][4];

void solve(void) {
	cin >> n;
	for (int i = 1; i <= 3; i++) cin >> A[i];
	for (int i = 0; i <= n; i++) {
	    for (int j = 0; j <= 3; j++) {
	     	dp[i][j] = -1;
	    }
	}
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 3; j++) {
		 	if (dp[i][j] == -1) continue;
		 	if (i+A[1] <= n) dp[i+A[1]][1] = max(dp[i+A[1]][1], dp[i][j] + 1);
		 	if (i+A[2] <= n) dp[i+A[2]][2] = max(dp[i+A[2]][2], dp[i][j] + 1);
		 	if (i+A[3] <= n) dp[i+A[3]][3] = max(dp[i+A[3]][3], dp[i][j] + 1);
	 	}
	}
	int ret = 0;
	for (int i = 1; i <= 3; i++) {
		if (dp[n][i] != -1) ret = max(ret, dp[n][i]);
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
