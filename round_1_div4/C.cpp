/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 09.12.2024 21:33:53
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n, k;
	cin >> n >> k;
	int temp = k / (n-1);
	if ((temp+k) % n == 0) {
	 	cout << temp+k-1 << endl;
	} else {
	 	cout << temp+k << endl;
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

	int t;
	cin >> t;
	while (t--) {
	 	solve();
	}

	return 0;
}
