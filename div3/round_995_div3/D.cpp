/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 22.12.2024 23:35:03
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
ll x, y;

void solve(void) {
	cin >> n >> x >> y;
	ll sum = 0;
	vector<ll> arr;
	for (int i = 1; i <= n; i++) {
		ll temp;
		cin >> temp;
		arr.push_back(temp);
		sum += temp;     	
	}
	sort(arr.begin(), arr.end());
	ll sum_left = sum - y;
	ll sum_right = sum - x;
	ll ret = 0;
	for (int i = 0; i < n; i++) {
	 	int left = lower_bound(arr.begin(), arr.end(), sum_left - arr[i]) - arr.begin();
	 	int right = upper_bound(arr.begin(), arr.end(), sum_right - arr[i]) - arr.begin();
		ret += max(0, right-left);
		if (left <= i && i < right) ret--;
	}
	ret /= 2;
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
