#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll xor_all(ll n) {
	if (n % 4 == 1) return 1;
	if (n % 4 == 2) return n+1;
	if (n % 4 == 3) return 0;
	return n;	
}	

ll cal(ll n, ll i, ll k) {
	if (n <= 0) return 0;
	ll all = xor_all(n);
	ll temp = n >> i;
	if (n % (1LL << i) < k) temp--;
	ll ret = xor_all(temp) << i;
	if (temp % 2 == 0) ret ^= k;
	return all ^ ret;
}

void solve(void) {
	ll l, r, i, k;
	cin >> l >> r >> i >> k;
	if (i == 0) {
		cout << 0 << endl;
		return;
	}
	cout << (cal(l-1, i, k) ^ cal(r, i, k)) << endl;
}
  
int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}	

	return 0;
}





