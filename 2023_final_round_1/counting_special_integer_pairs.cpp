/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-15 20:00:44 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 5e4+10;
int n;
ll k;
ll A[N], B[N], C[N];

ll cnt_pair(const ll& D) {
 	ll ret = 0ll;
 	int right = 0;
 	for (int left = 1; left <= n; left++) {
 	 	if (right < left+1) right = left+1;
 	 	while (right <= n && C[right] - C[left] <= D) right++;
 	 	ret += 1ll * (right-left-1);
 	}
 	return ret;
}

void solve(void) {
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
	 	C[i] = 0ll;
	}
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) {
	 	cin >> B[i];
	 	C[i] = A[i] - B[i];
	}
	sort(C+1, C+1+n);
	ll left = 0ll;
	ll right = 1e5;
	ll ret = -1ll;
	while (left <= right) {
		ll mid = (left+right)>>1;
		ll cnt = cnt_pair(mid);
		if (cnt >= k) {
		 	ret = mid;
		 	right = mid - 1;
		} else {
		 	left = mid + 1;
		}
	}
	if (ret == -1ll) {
	 	cout << -1 << endl;
	} else {
	 	if (cnt_pair(ret) == k) {
	 	 	cout << ret << endl;
	 	} else {
	 	 	cout << -1 << endl;
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

