/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 25.02.2025 21:10:20
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, k, p;

void solve(void) {
	cin >> n >> k >> p;
	if (k == 0) {
	 	cout << 0 << endl;
	 	return;
	}
	int cnt = 0;
	while (cnt < n) {
		cnt++;
		if (k >= -p && k <= p) {
		 	cout << cnt << endl;
		 	return;
		}
		if (k < -p) {
		 	k += p;
		 	continue;
		}
		if (k > p) {
		 	k -= p;
		}
	}
	cout << -1 << endl;
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
