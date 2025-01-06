/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 06.01.2025 21:31:39
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
ll c[N], v[N], g[N];
ll n, k, s, t;
ll l = 0, r = 5e9;

bool valid(ll mid) {
	ll ret = 0;
	ll temp = 0;
	for (int i = 1; i <= k; i++) {
		temp = g[i] - g[i-1];
		if (mid < temp) return false;
		ret += temp*2 - min(temp, mid-temp); 	
 	}
 	return ret <= t;
}

void solve(void) {
	cin >> n >> k >> s >> t;
	for (int i = 0; i < n; i++) {
	 	cin >> c[i] >> v[i];
	}
	for (int i = 1; i <= k; i++) cin >> g[i];
	g[++k] = s;
	sort(g,g+k+1);
	ll pos = -1;
	while (l <= r) {
	 	ll mid = (l+r) / 2;
	 	if (valid(mid)) {
	 		pos = mid;
			r = mid - 1;
	 	} else {
	 	 	l = mid + 1;
	 	}
	}
	if (pos == -1) {
	 	cout << -1 << endl;
	 	return;
	}
	ll ret = 5e9;
	for (int i = 0; i < n; i++) {
	 	if (v[i] >= pos) {
	 	 	ret = min(ret, c[i]);
	 	}
	}
	if (ret == 5e9) {
	 	cout << -1 << endl;
	 	return;
	}
	cout << ret << endl;                  
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
