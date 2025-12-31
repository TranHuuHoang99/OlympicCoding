/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-26 12:24:26 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int sum[12];
void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> sum[i];
	for (int i = 1; i <= n; i++) sum[i] += sum[i-1];
	int max_val = 0;
	for (int i = 1; i <= n; i++) {
	 	for (int j = i; j <= n; j++) {
			max_val = max(max_val, (sum[j]-sum[i-1])/(j-i+1));
	 	}
	}                                                         
	cout << max_val << endl;
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

