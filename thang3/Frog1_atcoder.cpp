/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 07.01.2025 19:55:28
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int dp[N];
int A[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 0; i <= n+10; i++) dp[i] = INT32_MAX;
	for (int i = 1; i <= n; i++) cin >> A[i];
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
	 	dp[i+1] = min(dp[i+1], dp[i] + abs(A[i] - A[i+1]));
	 	dp[i+2] = min(dp[i+2], dp[i] + abs(A[i] - A[i+2]));
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
