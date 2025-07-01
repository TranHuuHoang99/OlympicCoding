#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
int n, q;
int A[N];
int dp[N][40];

void solve(void) {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];	
	for (int i = 1; i <= n; i++) dp[i][0] = A[i];
	for (int j = 1; j <= 29; j++) {
	 	for (int i = 1; i <= n; i++) {
	 	 	int nextPlanet = dp[i][j-1];
	 	 	dp[i][j] = dp[nextPlanet][j-1];
	 	}
	}
	for (int i = 1; i <= q; i++) {
	 	int x, k;
	 	cin >> x >> k;
	 	for (int j = 29; j >= 0; j--) {
	 	 	if (k >= (1 << j)) {
	 	 	 	x = dp[x][j];
	 	 	 	k -= (1 << j);
	 	 	}
	 	}
	 	cout << x << endl;
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
	solve();
	return 0;
}

