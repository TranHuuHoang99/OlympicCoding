/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-14 11:40:20 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n, k;
int A[N];
int H[N];
int prefix_val[N];
int prefix_height[N];
bool isValid(int val) {
	for (int i = 1; i <= n-val+1; i++) {
		if (prefix_height[i] < val) continue;
		int temp = prefix_val[i+val-1] - prefix_val[i-1];
		if (temp <= k) return true;
	}
	return false;
}
void solve(void) {
 	cin >> n >> k;
 	for (int i = 1; i <= n; i++) {
 	 	cin >> A[i];
 	 	prefix_val[i] = prefix_val[i-1] + A[i];
 	}
 	for (int i = 1; i <= n; i++) cin >> H[i];
	prefix_height[n] = 1;
	for (int i = n-1; i >= 1; i--) {
	 	if (H[i] % H[i+1] == 0) {
	 	 	prefix_height[i] = prefix_height[i+1] + 1;
	 	} else {
	 	 	prefix_height[i] = 1;
	 	}
	}
	int left = 1;
	int right = n;
	int ret = 0;
	while (left <= right) {
	 	int mid = (left+right)>>1;
	 	if (isValid(mid)) {
	 	 	ret = mid;
	 	 	left = mid + 1;
	 	} else {
	 	    right = mid - 1;
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

