/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-09 16:28:22 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 16;
const ll MAX_MASK = (1 << 16) + 10;
int n;
ll A[N+10][N+10];
ll dp[MAX_MASK];
ll cost[MAX_MASK];

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < n; j++) {
	 	    cin >> A[i][j];
	 	}	
	}
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
		 	if (!(mask & (1 << i))) continue;
		 	for (int j = i+1; j < n; j++) {
		 	 	if (!(mask&(1<<j))) continue;
		 	 	cost[mask] += A[i][j];
		 	}
		}
	}	
	for (int mask = 0; mask < (1 << n); mask++) dp[mask] = LLONG_MIN;
	dp[0] = 0ll;
	for (int mask = 0; mask < (1 << n); mask++) {
		dp[mask] = cost[mask];
	 	for (int submask = mask; submask > 0; submask = (submask-1)&mask) {
	 	 	if (dp[submask] == LLONG_MIN) continue;
	 	 	dp[mask] = max(dp[mask], dp[mask-submask] + cost[submask]);
	 	}
	}
	cout << dp[(1<<n)-1] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

