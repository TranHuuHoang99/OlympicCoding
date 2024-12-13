/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 13.12.2024 12:13:26
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int left = 2, right = 999;
	int ret = -1;
	while (left <= right) {
	 	int mid = (right+left) / 2;
	 	cout << "?" << ' ' << 1 << ' ' << mid << endl;
	 	int temp;
	 	cin >> temp;
	 	if (temp == mid) {
	 	 	left = mid + 1;
	 	} else {
	 	 	ret = mid;
	 	 	right = mid - 1;
	 	}
	}
	cout << "!" << ' ' << ret << endl;
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
