/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 10.12.2024 23:20:56
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n;
	cin >> n;
	if (n <= 3) {
	 	cout << -1 << endl;
	 	return;
	}
	int temp = n-1 + n%2;
	for (temp; temp >= 1; temp-=2) cout << temp << ' ';
	for (int i = 4; i <= n; i+=2) {
	 	cout << i << ' ';
	 	if (i == 4) cout << 2 << ' ';
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
