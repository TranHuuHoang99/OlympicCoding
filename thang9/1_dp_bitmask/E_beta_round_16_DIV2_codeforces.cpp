/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-08 20:20:23 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 18+10;
const ll MAX_MASK = (1 << 18) + 10;
int n;
double A[N][N];
double dp[MAX_MASK];	

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < n; j++) {
	 	 	cin >> A[i][j];
	 	}
	}
	for (int mask = 0; mask < (1 << n); mask++) dp[mask] = 0.0f;
	dp[(1<<n)-1] = 1.0f;
	for (int mask = (1 << n)-1; mask >= 0; mask--) {
	 	if (dp[mask] == 0.0f) continue;
	 	for (int i = 0; i < n; i++) {
	 	 	if (!(mask & (1 << i))) continue;
	 	 	for (int j = 0; j < n; j++) {
	 	 	 	if (!(mask & (1 << j)) || i == j) continue;
	 	 	 	int numbFishAlive = __builtin_popcount(mask);
	 	 	 	int prop_2_fish_meet = (numbFishAlive * (numbFishAlive - 1)) >> 1; // C(2, numbFishAlive)
	 	 	 	// fish i eat fish j
	 	 	 	dp[mask - (1 << j)] += dp[mask] * A[i][j] / prop_2_fish_meet;
	 	 	}
	 	}
	}
	for (int i = 0; i < n; i++) cout << fixed << setprecision(6) << dp[(1<<i)] << ' ';
	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

