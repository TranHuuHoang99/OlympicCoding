/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-09 17:51:15 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e4+10;
const int MAX_MASK = (1 << 4) + 10;
int n;
int A[4][N];
int dp[N][MAX_MASK];

bool check_valid(int mask, int nextmask) {
 	for (int i = 0; i < 4; i++) {
 	 	if ((mask & (1<<i)) && (nextmask & (1<<i))) return false;
 	}
	for (int i = 0; i < 3; i++) {
	    if ((nextmask & (1 << i)) && (nextmask & (1 << (i+1)))) return false;
	}
	return true;	
}

void solve(void) {
 	cin >> n;
 	int max_val = INT32_MIN;
 	for (int i = 0; i < 4; i++) {
 	 	for (int j = 1; j <= n; j++) {
 	 	 	cin >> A[i][j];
 	 	 	max_val = max(max_val, A[i][j]);
 	 	}
 	}
 	for (int i = 0; i <= n; i++) {
 	 	for (int mask = 0; mask < (1 << 4); mask++) {
 	 	 	dp[i][mask] = INT32_MIN;
 	 	}
 	}
 	dp[0][0] = 0;
 	for (int i = 0; i < n; i++) {
 	 	for (int mask = 0; mask < (1 << 4); mask++) {
 	 	    if (dp[i][mask] == INT32_MIN) continue;
 	 	    for (int nextmask = 0; nextmask < (1 << 4); nextmask++) {
 	 	     	if (!check_valid(mask, nextmask)) continue;
 	 	     	int temp = 0;
 	 	     	for (int j = 0; j < 4; j++) {
 	 	     	 	if (nextmask & (1 << j)) temp += A[j][i+1];
 	 	     	}
 	 	     	dp[i+1][nextmask] = max(dp[i+1][nextmask], dp[i][mask] + temp);
 	 	    }
 	 	}	
 	}
 	int ret = INT32_MIN;
 	for (int mask = 0; mask < (1 << 4); mask++) ret = max(ret, dp[n][mask]);
 	if (ret == 0) {
 	 	cout << max_val << endl;
 	} else {
 	 	cout << ret << endl;
 	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

