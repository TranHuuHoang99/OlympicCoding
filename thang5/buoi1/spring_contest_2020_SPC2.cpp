/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 08.04.2025 20:00:12
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
ll A[N];
ll n;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	ll sum1 = 0ll;
	for (int i = 1; i <= n; i++) sum1 += A[i];
	sort(A+1,A+1+n);
	for (int i = 1; i <= n; i++) {
	 	sum1 += 2ll * (2ll * i - n) * A[i];
	 	sum1 -= 2ll * A[i];
	}
	ll m_gcd = __gcd(sum1, n);
	cout << (sum1/m_gcd) << ' ' << (n/m_gcd) << endl;
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
