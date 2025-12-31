/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-09 20:33:32 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n;
ll c;
ll A[N];
ll get_val(ll a) {
	ll ret = 0;
	for (int i = 1; i <= n; i++) {
		ll temp = A[i] + 2ll * a;
		ret += temp * temp;
		if (ret > c) return ret;
	}
	return ret;
}
void solve(void) {
	cin >> n >> c;
	for (int i = 1; i <= n; i++) cin >> A[i];
	ll left = 1;
	ll right = 1e9;
	while (left <= right) {
		ll mid = (left+right)>>1;
		ll val = get_val(mid);
		if (val > c) {
			right = mid - 1;
		} else if (val < c) {
		 	left = mid + 1;
		} else {
		 	cout << mid << endl;
		 	return;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}

