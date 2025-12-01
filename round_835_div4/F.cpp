/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-11-27 22:07:46 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n, d;
ll c;
ll A[N];
bool cmp(ll a, ll b) {
 	return a > b;
}
ll get_val(int dist) {
	ll ret = 0;
	for (int i = 0; i < d; i++) {
	 	if (i%dist < n) {
	 	 	ret += A[i%dist];
	 	}
	}
	return ret;
}
void solve(void) {
	cin >> n >> c >> d;
	for (int i = 0; i < n; i++) cin >> A[i];
	sort(A, A+n, cmp);
	int left = 1;
	int right = d+10;
	int ret = -1;
	while (left <= right) {
	    int mid = (left+right)>>1;
	    if (get_val(mid) >= c) {
	     	ret = mid;
	     	left = mid + 1;
	    } else {
	        right = mid - 1;
	    }	
	}	
	if (ret == -1) {
	 	cout << "Impossible" << endl;
	} else if (ret == d+10) {
	 	cout << "Infinity" << endl;
	} else {
	 	cout << ret-1 << endl;
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

