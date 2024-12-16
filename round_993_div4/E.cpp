/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 15.12.2024 22:46:52
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	ll k, l1, r1, l2, r2;
	cin >> k >> l1 >> r1 >> l2 >> r2;
	ll ret = 0;
	ll kn = 1;
	while (kn <= 1e9) {
	 	ret += max(min(r1,r2/kn) - max(l1, (l2+kn-1)/kn) + 1, 0ll);
	 	kn *= k;
	}
	cout << ret << endl;
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
