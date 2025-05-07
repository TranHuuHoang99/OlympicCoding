#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 510;
int n;
ll A[N][N], sumRow[N][N], sumCol[N][N];
bool dp[N][N];

void init(void) {
 	for (int i = 0; i <= n; i++) {
 	 	for (int j = 0; j <= n; j++) {
 	 	 	dp[i][j] = false;
 	 	 	sumRow[i][j] = 0;
 	 	 	sumCol[i][j] = 0;
 	 	}
 	}
}

void solve(void) {
	cin >> n;
	init();
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= n; j++) {
	 	 	cin >> A[i][j];
	 	}
	}
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= n; j++) {
	 	 	sumRow[i][j] = sumRow[i-1][j] + A[i][j];
	 	 	sumCol[i][j] = sumCol[i][j-1] + A[i][j];
	 	}
	}
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= n; j++) {
	 	    if (sumRow[i][j] % 2 == 0) {
	 	     	if (dp[i][j-1] == false) {
	 	     	 	dp[i][j] = true;
	 	     	}
	 	    }
	 	    if (sumCol[i][j] % 2 == 0) {
	 	     	if (dp[i-1][j] == false) {
	 	     	 	dp[i][j] = true;
	 	     	}
	 	    }
	 	}	
	}
	if (dp[n][n] == true) {
	 	cout << "YES" << endl;
	} else {
	 	cout << "NO" << endl;
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

