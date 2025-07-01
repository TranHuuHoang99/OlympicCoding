#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
int n, q;
int A[N];
int dp[N][20]; // sparse table

void solve(void) {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) {
	 	dp[i][0] = A[i];
	}
	for (int j = 1; j <= 18; j++) {
	 	for (int i = 1; i <= n; i++) {
	 	    if (i + (1 << j) - 1 <= n) {
	 	        dp[i][j] = min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
	 	    }	
	 	}	
	}
	for (int i = 1; i <= q; i++) {
	 	int left, right;
	 	cin >> left >> right;
	 	int len = log2(right-left+1);
	 	cout << min(dp[left][len], dp[right-(1<<len)+1][len]) << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

