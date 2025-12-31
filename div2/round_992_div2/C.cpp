/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 09.12.2024 09:57:17
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

#define max_bin 60 // max of 2 ^ 60 is 1e18

void func(int l, int r, int next, const ll k, vector<int> &ret) {
 	if (l == r) {
		ret[l] = next;
		return;
 	}
 	int temp = r-l-1;
 	if (temp < max_bin && (1ll << temp) < k) {
 	 	ret[r] = next;
 	 	func(l, r-1, next+1, k-(1ll << temp), ret);	
 	} else {
		ret[l] = next;
		func(l+1,r, next+1, k, ret);
 	}
}

void solve(void) {
	ll n, k;
	cin >> n >> k;
	if (n-1 < max_bin && (1ll << (n-1)) < k) {
	 	cout << -1 << endl;
	 	return;
	}
	vector<int> ret(n);
	func(0,n-1, 1,k,ret);
	for (int i = 0; i < ret.size(); i++) cout << ret[i] << ' ';
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
