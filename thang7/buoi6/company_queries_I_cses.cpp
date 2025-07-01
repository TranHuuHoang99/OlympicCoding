#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
int n, q;
int A[N];
int dp[N][20]; // nguoi cach nguoi i 1 cap bac la 2^j

void solve(void) {
	cin >> n >> q;
	A[1] = 1;
	for (int i = 2; i <= n; i++) cin >> A[i];
	for (int i = 2; i <= n; i++) dp[i][0] = A[i];
	for (int j = 1; j <= 18; j++) {
	    for (int i = 1; i <= n; i++) {
	     	if (dp[i][j-1] != -1) {
	     	    int bossMid = dp[i][j-1];
	     	    if (dp[bossMid][j-1] != -1) {
	     	        dp[i][j] = dp[bossMid][j-1];
	     	    }	
	     	}	
	    }
	}
	for (int i = 1; i <= q; i++) {
	 	int x, k;
	 	cin >> x >> k;
	 	for (int j = 18; j >= 0; j--) {
	 	 	if (k >= (1 << j)) {
	 	 	 	x = dp[x][j];
	 	 	 	k -= (1 << j);
	 	 	}
	 	}
	 	cout << (x == 0 ? -1 : x) << endl;
	}	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

