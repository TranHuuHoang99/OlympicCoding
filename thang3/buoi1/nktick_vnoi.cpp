/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 07.01.2025 20:50:47
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 6e5+1;
int T[N];
int R[N];
int dp[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> T[i];
	for (int i = 1; i <= n-1; i++) cin >> R[i];
	dp[0] = 0;
	dp[1] = T[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = min(dp[i-1]+T[i], dp[i-2]+R[i-1]); 	
	}
	cout << dp[n] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
