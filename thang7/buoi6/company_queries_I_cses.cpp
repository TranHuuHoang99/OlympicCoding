#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
int n, q;
int dp[N][30];

void solve(void) {
 	cin >> n >> q;
 	for (int i = 2; i <= n; i++) {
 	 	int temp;
 	 	cin >> temp;
 	 	dp[i][0] = temp;
 	}
 	for (int j = 1; j <= 18; j++) {
 	 	for (int i = 1; i <= n; i++) {
 	 	 	int bossMid = dp[i][j-1];
 	 	 	dp[i][j] = dp[bossMid][j-1];
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
#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG
	solve();
	return 0;
}

