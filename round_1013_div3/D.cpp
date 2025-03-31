/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 02.04.2025 22:43:44
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, k;

void solve(void) {
	cin >> n >> m >> k;
	ll ret = -1;
	ll left = 1;
	ll right = m;
	while (left <= right) {
	 	ll mid = (left+right) / 2;
	 	if (((m/(mid+1)) * mid + m%(mid+1)) * n >= k) {
	 	 	ret = mid;
	 	 	right = mid - 1;
	 	} else {
	 	 	left = mid + 1;
	 	}
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
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}
