/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 14.12.2024 14:05:55
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n;
	cin >> n;
	int sum = 0;
	int min_val = INT32_MAX;
	for (int i = 0; i < n; i++) {
	 	int temp;
	 	cin >> temp;
	 	sum += temp;
	 	min_val = min(min_val, temp);
	}
	int temp_sum = min_val * n;
	cout << sum - temp_sum << endl;
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
