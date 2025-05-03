#include <bits/stdc++.h>
#define ll long long

using namespace std;

int A[32];
int sum[32];
int dp[32][32][32];
int n, k, t;

void init(void) {
 	for (int i = 0; i <= n; i++) {
 	 	sum[i] = 0;
 	 	A[i] = 0;
 	}
 	for (int i = 0; i <= 31; i++) {
 	 	for (int j = 0; j <= 31; j++) {
 	 	    for (int k = 0; k <= 31; k++) dp[i][j][k] = 0;
 	 	}	
 	}
}

void solve(void) {
	cin >> n >> k >> t;
	init();
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
	 	sum[i] = sum[i-1] + A[i];
	}
	for (int i = 1; i <= n; i++) {
	 	for (int cur = 0; cur <= 31; cur++) {
	 	 	for (int opp = 0; opp <= 31; opp++) {
	 	 	 	for (int add = 0; add <= cur && add <= i-1; add++) {
	 	 	 	 	dp[i][cur][opp] = max(dp[i][cur][opp], sum[i] - dp[i-1-add][opp][cur-add]);
	 	 	 	}
	 	 	}
	 	}
	}
	int first = dp[n][k][t];
	int second = sum[n] - first;
	if (first > second) {
	 	cout << "WIN" << endl;
	} else if (first < second) {
	 	cout << "LOSE" << endl;
    } else {
     	cout << "DRAW" << endl;
    }                  
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}

