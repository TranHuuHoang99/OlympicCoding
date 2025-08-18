/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-18 22:08:39 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
const ll max_mask = (1 << 20) + 10;
int n;
int A[N];
int dp1[max_mask][23];
int dp2[max_mask][23];

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
	    cin >> A[i];
	    dp1[A[i]][0]++;
	    dp2[A[i]][0]++;
	}	
	for (int mask = 0; mask < (1 << 20); mask++) {
		for (int i = 1; i <= 20; i++) {
		 	dp1[mask][i] += dp1[mask][i-1];
		 	if (mask & (1 << (i-1))) {
		 	 	dp1[mask][i]  += dp1[mask^(1<<(i-1))][i-1];
			}
		}
	}
	for (int mask = (1 << 20)-1; mask >= 0; mask--) {
	 	for (int i = 1; i <= 20; i++) {
	 	    dp2[mask][i] += dp2[mask][i-1];
	 	    if (!(mask & (1 << (i-1)))) {
	 	        dp2[mask][i] += dp2[mask|(1<<(i-1))][i-1];
	 	    }	
	 	}	
	}
	for (int i = 1; i <= n; i++) {
	 	cout << dp1[A[i]][20] << ' ' << dp2[A[i]][20] << ' ' << (n - dp1[(1<<20)-1-A[i]][20])<< endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

