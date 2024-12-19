/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 18.12.2024 20:46:04
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+1;
int A[N];
int update[N];
int n, k;

bool valid(int mid) {
 	if (mid == 0) {
 	 	for (int i = 2; i <= n; i++) {
 	 	 	if (A[i] - A[i-1] > 0) return false;
 	 	}
 	 	return true;
 	}
	for (int i = 1; i <= n-1; i++) {
	 	update[i] = A[i+1]-A[i];
	}
	int ret = 0;
	for (int i = 1; i <= n-1; i++) {
	 	ret += (update[i]+mid-1)/mid - 1;
	}
	return ret <= k;
}

void solve(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	int left = 0;
	int right = 1e9;
	int ret = 0;
	while (left <= right) {
	 	int mid = (left+right) / 2;
	 	if (valid(mid)) {
	 		ret = mid;
	 		right = mid - 1;
	 		if (ret == 0) break;
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
	int cnt = 1;
	while (t--) {
		cout << "Case" << ' ' << "#" << cnt << ":" << ' ';
	 	solve();
	 	cnt++;
	}

	return 0;
}
