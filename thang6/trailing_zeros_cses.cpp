#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll fast_pow(ll a, ll b) {
 	ll ret = 1ll;
 	while (b) {
 	 	if (b&1) ret = ret * a;
 	 	a = a * a;
 	 	b >>= 1;
 	}
 	return ret;
}

void solve(void) {
	ll n;
	cin >> n;
	int ret = 0;
	for (int i = 1; i <= n; i++) {
	 	ll temp = fast_pow(5ll, 1ll * i);
	 	if (n / temp == 0) break;
	 	ret += int(n/temp);
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

