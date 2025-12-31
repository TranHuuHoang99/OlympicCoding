#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll cal1(ll n) {
	if (n % 4 == 1) return 1;
	if (n % 4 == 2) return n+1;
	if (n % 4 == 3) return 0;
	return n;
}

ll cal2(ll n, ll i, ll k) {
	ll temp = n >> i;
	temp <<= i;
	if (temp + k <= n) {
		temp = n >> i;
	} else {
		temp = n >> i;
		temp -=1;
	}
	if (temp < 0) return 0;
	ll ret = cal1(temp);
	ret <<= i;
	if (temp % 2 == 0) ret += k;
	return ret;
}

void solve(void) {
	ll l, r, i, k;
	cin >> l >> r >> i >> k;
	cout << (cal1(l-1) ^ cal2(l-1,i,k) ^ cal1(r) ^ cal2(r,i,k)) << endl;
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





