/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-12 20:38:56 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e6+10;
const int mask_max = (1 << 22) + 10;
int n;
int A[N];
int dp[mask_max];

void solve(void) {
 	cin >> n;
 	for (int i = 1; i <= n; i++) cin >> A[i];
 	for (int mask = 0; mask < (1 << 22); mask++) dp[mask] = -1;
 	for (int i = 1; i <= n; i++) dp[A[i]] = A[i];
 	for (int mask = 0; mask < (1 << 22); mask++) {
 	 	for (int i = 0; i < 22; i++) {
 	 	 	if ((mask & (1 << i)) && (dp[mask-(1<<i)] != -1)) {
 	 	 	 	dp[mask] = dp[mask-(1<<i)];
 	 	 	}
 	 	}
 	}
 	for (int i = 1; i <= n; i++) cout << dp[(1<<22)-1-A[i]] << ' ';
 	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

