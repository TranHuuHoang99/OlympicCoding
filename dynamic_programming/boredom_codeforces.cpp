/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 17.02.2025 21:14:03
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int A[N], cnt[N];
ll dp[N];
int n;

void solve(void) {
	cin >> n;
	int max_val = 0;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
	 	cnt[A[i]]++;
	 	max_val = max(max_val, A[i]);
 	}
 	dp[0] = 0;
 	dp[1] = cnt[1];
 	for (int i = 2; i <= max_val; i++) {
 	 	dp[i] = max(dp[i-1], dp[i-2] + 1ll * (ll)cnt[i] * i);
 	}
 	ll ret = 0;
 	for (int i = 1; i <= max_val; i++) {
 	 	ret = max(ret, dp[i]);
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
