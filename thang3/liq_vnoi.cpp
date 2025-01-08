/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 07.01.2025 20:05:59
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+10;
int A[N];
int dp[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 0; i <= n+10; i++) dp[i] = 1;
	for (int i = 1; i <= n; i++) cin >> A[i];
	dp[1] = 1;
	for (int i = 1; i <= n; i++) {
	 	for (int j = i+1; j <= n; j++) {
	 	 	if (dp[i] != INT32_MIN && A[i] < A[j]) {
	 	 	 	dp[j] = max(dp[j], dp[i] + 1);
	 	 	}
	 	}
	}
	int ret = INT32_MIN;
	for (int i = 1; i <= n; i++) ret = max(ret, dp[i]);
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
