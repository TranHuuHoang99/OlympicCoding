/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 06.12.2024 22:37:17
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
ll A[N];
int n, q;

void solve(void) {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	vector<ll> arr(n);
	for (int i = 1; i <= n-1; i++) {
	 	arr[i] = abs(A[i]-A[i+1]);
	}
	vector<vector<ll>> st(18, vector<ll>(n));
	for (int i = 1; i <= n-1; i++) st[0][i] = arr[i];
	for (int i = 1; i <= 17; i++) {
	 	for (int j = 1; j+(1<<i)-1 <= n-1; j++) {
	 	 	st[i][j] = __gcd(st[i-1][j], st[i-1][j+(1<<(i-1))]);
	 	}
	}
	for (int i = 0; i < q; i++) {
	 	int l, r;
	 	cin >> l >> r;
	 	r--;
	 	if (r < l) {
	 	 	cout << 0 << ' ';
	 	 	continue;
	 	}
	 	int k = __lg(r-l+1);
	 	cout << __gcd(st[k][l], st[k][r-(1<<k)+1]) << ' ';
	}
	cout << endl;
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
	while (t--) {
	 	solve();
	}

	return 0;
}
