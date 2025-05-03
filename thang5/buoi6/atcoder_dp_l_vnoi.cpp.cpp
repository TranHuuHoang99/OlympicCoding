#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e3+10;
ll A[N];
ll sum[N];
ll dp[N][N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
	 	sum[i] = sum[i-1] + A[i];
	}
	for (int i = 1; i <= n; i++) {
	 	dp[i][i] = A[i];
	}
	for (int i = n-1; i >= 1; i--) {
	 	for (int j = i+1; j <= n; j++) {
	 	 	// ta lay la bai o ben trai
	 	 	dp[i][j] = max(dp[i][j], sum[j] - sum[i-1] - dp[i+1][j]);
	 	 	// ta lay la bai o ben phai
	 	 	dp[i][j] = max(dp[i][j], sum[j] - sum[i-1] - dp[i][j-1]);
	 	}
	}
	ll X = dp[1][n];
	ll Y = sum[n] - X;
	cout << X-Y << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

