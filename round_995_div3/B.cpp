/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 22.12.2024 21:52:34
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	ll n, a, b, c;
	cin >> n >> a >> b >> c;
	ll temp = a + b + c;
	if (n == temp) {
	 	cout << 3 << endl;
	 	return;
	}
	if (n < temp) {
	 	ll sum = 0;
	 	int cnt = 0;
	 	if (sum + a >= n) {
	 	 	cout << 1 << endl;
	 	 	return;
		}
		sum += a;
		if (sum + b >= n) {
		 	cout << 2 << endl;
		 	return;
		}
		cout << 3 << endl;
		return;
	}
	ll ret = (n/temp) * 3;
	ll mod = n % temp;
	if (mod == 0) {
	 	cout << ret << endl;
	 	return;
	}
	ll sum = 0;
	if (sum + a >= mod) {
	 	cout << ret + 1 << endl;
	 	return;
	}
	sum += a;
	if (sum + b >= mod) {
	 	cout << ret + 2 << endl;
	 	return;
	}
	cout << ret + 3 << endl;
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
