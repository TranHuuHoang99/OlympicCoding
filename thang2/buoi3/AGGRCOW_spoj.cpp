/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 17.12.2024 23:46:11
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+1;
ll A[N];
int n, c;

bool valid(ll a) {
 	ll ret = 1;
 	ll temp = A[1];
 	for (int i = 2; i <= n; i++) {
 	 	if (A[i] - temp >= a) {
 	 	 	temp = A[i];
 	 	 	ret++;
 	 	}
 	}
 	return ret >= c;
}

void solve(void) {
	cin >> n >> c;
	for (int i = 1; i <= n; i++) cin >> A[i];
	ll left = 1;
	ll right = 1e18;
	ll ret = 0;
	sort(A+1, A+n+1);
	while (left <= right) {
	 	ll mid = (left + right) / 2;
	 	if (valid(mid)) {
	 		ret = mid;
	 	 	left = mid + 1;
	 	}  else {
	 	 	right = mid - 1;
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
	while (t--) {
	 	solve();
	}

	return 0;
}
