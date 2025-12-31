/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-11-16 18:41:14 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n, q;
ll A[N];
ll prefix[N];
ll sum[N];
void solve(void) {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	memset(prefix, 0, sizeof(prefix));
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= n; i++) {
	 	prefix[i] = max(prefix[i-1], A[i]);
	 	sum[i] = sum[i-1] + A[i];
	}
	for (int i = 1; i <= q; i++) {
		int k;
		cin >> k;
		int left = 1;
		int right = n;
		ll ans = 0ll;
		while (left <= right) {
			int mid = (left+right)>>1;
			if (prefix[mid] <= k) {
				ans = sum[mid];
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		cout << ans << ' ';
	}
	cout << "\n";
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

