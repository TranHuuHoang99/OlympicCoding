/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 08.12.2024 21:41:21
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n, k;
	cin >> n >> k;
	vector<int> ret(n+1);
	for (int i = 1; i <= n; i++) cin >> ret[i];
	for (int i = 1; i <= n; i++) {
		bool valid = true;
	 	for (int j = 1; j <= n; j++) {
	 	 	if (i == j) continue;
			if (abs(ret[i]-ret[j]) % k == 0) valid = false;
	 	}
	 	if (valid) {
	 	 	cout << "yes" << endl;
	 	 	cout << i << endl;
	 	 	return;
	 	}
	}
	cout << "no" << endl;
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
