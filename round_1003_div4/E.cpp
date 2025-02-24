/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 24.02.2025 21:02:01
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m, k;

void solve(void) {
	cin >> n >> m >> k;
	if (max(n,m) - min(n,m) > k || k > max(n,m)) {
	 	cout << -1 << endl;
	 	return;
	}
	pair<int,int> zero = {0, n};
	pair<int,int> one = {1, m};
	if (n < m) swap(zero,one);
	for (int i = 0; i < k; i++) {
	 	cout << zero.first;
	 	zero.second--;
	}
	while (one.second > 0) {
	 	cout << one.first;
	 	one.second--;
	 	swap(zero,one);
	}
	while (zero.second > 0) {
	 	cout << zero.first;
	 	zero.second--;
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
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}
