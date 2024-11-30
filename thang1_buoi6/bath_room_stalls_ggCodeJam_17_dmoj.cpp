/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 30.11.2024 21:04:08
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, k;

void solve(void) {
	map<ll,ll> tracking;
	pair<ll,ll> ret;
	cin >> n >> k;
	priority_queue<ll> pq;
	pq.push(n);
	tracking[n] = 1;
	while (k > 0 && !pq.empty()) {
	 	ll val1 = pq.top();
	 	pq.pop();
	 	ll left_val = val1 / 2;
	 	ll right_val = val1 - left_val - 1;
	 	ll val2 = tracking[val1];
	 	if (tracking.find(left_val) == tracking.end()) {
	 	 	pq.push(left_val);
	 	}
	 	tracking[left_val] += val2;
	 	if (tracking.find(right_val) == tracking.end()) {
	 	 	pq.push(right_val);
	 	}
	 	tracking[right_val] += val2;
		k -= val2;
		ret = {max(left_val,right_val), min(left_val,right_val)};
	}
	cout << ret.first << ' ' << ret.second << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	int cnt = 1;
	while (t--) {
	 	cout << "Case #" << cnt << ": ";
	 	solve();
	 	cnt++;
	}

	return 0;
}
