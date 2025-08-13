/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-08 19:47:22 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 16;
const ll MAX_MASK = (1<<N) + 10;
int n;
int A[N+10][N+10];
int dp[MAX_MASK][N+10];

void solve(void) {
 	int n;
 	cin >> n;
 	for (int i = 0; i < n; i++) {
 	 	for (int j = 0; j < n; j++) {
 	 	 	cin >> A[i][j];
 	 	}
 	}
 	for (int mask = 0; mask < (1 << n); mask++) {
 	    for (int i = 0; i < n; i++) {
 	     	dp[mask][i] = INT32_MAX;
 	    }
 	}
 	for (int i = 0; i < n; i++) dp[(1 << i)][i] = 0;
 	for (int mask = 0; mask < (1 << n); mask++) {
 	 	for (int i = 0; i < n; i++) {
 	 	 	for (int j = 0; j < n; j++) {
 	 	 	 	if (dp[mask][i] != INT32_MAX && (mask & (1 << i)) && !(mask & (1 << j))) {
 	 	 	 	 	dp[mask | (1<<j)][j] = min(dp[mask | (1<<j)][j], dp[mask][i] + A[i][j]);
 	 	 	 	}
 	 	 	}
 	 	}
	}
	int ret = INT32_MAX;
	for (int i = 0; i < n; i++) {
	 	ret = min(ret, dp[(1<<n)-1][i]);
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

