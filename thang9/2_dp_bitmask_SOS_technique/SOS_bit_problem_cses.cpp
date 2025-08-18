/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-14 23:14:11 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
const int max_mask = (1 << 20) + 10;
int n;
int A[N];
int dp_or[max_mask]; // OR
int dp_and[max_mask]; // AND

void solve(void) {
 	cin >> n;
 	for (int i = 1; i <= n; i++) {
 	    cin >> A[i];
 	    dp_or[A[i]]++;
 	    dp_and[A[i]]++;
 	}
 	for (int i = 1; i <= 20; i++) {
 	 	for (int mask = 0; mask < (1<<20); mask++) {
 	 	    if (mask & (1 << (i-1))) {
 	 	     	dp_or[mask] += dp_or[mask^(1<<(i-1))];
 	 	    }
 	 	}	
 	}
 	for (int i = 1; i <= 20; i++) {
 	 	for (int mask = (1<<20)-1; mask >= 0; mask--) {
 	 	 	if (!(mask & (1<<(i-1)))) {
 	 	 	 	dp_and[mask] += dp_and[mask|(1<<(i-1))];
 	 	 	}
 	 	}
 	}
 	for (int i = 1; i <= n; i++) {
 	 	cout << dp_or[A[i]] << ' ' << dp_and[A[i]] << ' ' << n - dp_or[(1<<20)-1-A[i]] << endl;
 	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

