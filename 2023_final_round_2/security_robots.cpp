/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-16 21:34:42 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 3e4+10;
int n, m;
ll A[N];

void solve(void) {
 	cin >> n >> m;
 	n--;
 	for (int i = 1; i <= n; i++) cin >> A[i];
 	ll left = 0;
 	ll right = 1e18;
 	ll ret = 0;
 	while (left <= right) {
 	 	ll mid = (left+right)>>1;
 	 	int cnt = 0;
 	 	ll sum = 0;
 	 	ll temp = 0;
 	 	ll mul = 0;
 	 	for (int i = 1; i <= n; i++) {
 	 	 	mul++;
 	 	 	temp += A[i-1] * (mul-1);
 	 	 	sum += A[i] * mul + temp;
 	 	 	if (sum >= mid) {
 	 	 	 	cnt++;
 	 	 	 	sum = 0;
 	 	 	 	temp = 0;
 	 	 	 	mul = 0;
 	 	 	}
 	 	}
 	 	if (cnt < m) {
 	 	 	right = mid - 1;
 	 	} else {
 	 		ret = mid;
 	 	 	left = mid + 1;
 	 	}
  	}
	cout << ret << endl;
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

