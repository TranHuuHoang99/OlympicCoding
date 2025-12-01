/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-11-23 22:06:28 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n;
int prefix[N];
int suffix[N];
int A[N];
void solve(void) {
	cin >> n;
	memset(prefix, 0, sizeof(prefix));
	memset(suffix, 0, sizeof(suffix));
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) {
	 	prefix[i] = max(prefix[i-1], A[i]);
	}
	for (int i = n; i >= 1; i--) {
	 	suffix[i] = max(suffix[i+1], A[i]);
	}
	for (int i = 1; i <= n; i++) {
	 	int max_val = max(prefix[i-1], suffix[i+1]);
	 	cout << A[i] - max_val << ' ';
	}
	cout << endl;
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

