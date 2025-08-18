/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-17 15:24:33 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int max_mask = (1<<24)+10;
int n;
int dp[max_mask];

void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
     	string str;
     	cin >> str;
     	int mask = 0;
     	for (int j = 0; j < str.size(); j++) {
     	 	mask |= (1 << (str[j]-'a'));
     	}
     	dp[mask]++;
    }
   	for (int i = 0; i < 24; i++) {
   	    for (int mask = 0; mask < (1 << 24); mask++) {
   	     	if (mask & (1 << i)) {
   	     	 	dp[mask] += dp[mask^(1<<i)];
   	     	}
   	    }	
   	}	
   	ll ret = 0ll;
 	for (int mask = 0; mask < (1<<24); mask++) {
 		ll temp = 1ll * (n - dp[(1<<24)-1-mask]); // xet nhung mask co cac chu cai nam ngoai subset
 		// sau do lay n - mask (la tap hop gom cac chu cai nam ngoai subset
 		ret ^= temp * temp;
 	}
 	cout << ret << endl;	  		
}	

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

