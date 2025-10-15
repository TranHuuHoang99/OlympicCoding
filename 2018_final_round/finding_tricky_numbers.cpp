/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-12 22:01:45 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9+7;
int A, K;
ll dp[20][15];

void solve(void) {
	cin >> A >> K;
	for (int i = 1; i <= 9; i++) dp[1][i] = 1ll;
	for (int i = 1; i <= 18; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
			 	if (abs(j-k) >= A) {
			 	 	dp[i+1][k] += dp[i][j];
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

