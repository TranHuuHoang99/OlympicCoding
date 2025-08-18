/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-22 23:29:16 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int q;
ll dp[43][2][2][3];

void cal_cows(ll x, ll y, ll d) {
 	memset(dp, 0ll, sizeof(dp));
 	vector<int> digitx, digity, digitd;
 	for (int i = 1; i <= 42; i++) {
 	 	digitx.push_back(x%3);
 	 	x /= 3;
 	 	digity.push_back(y%3);
 	 	y /= 3;
 	 	digitd.push_back(d%3);
 	 	d /= 3;
 	}
	dp[0][0][0][1] = 1ll;
	for (int i = 0; i < 42; i++) {
	 	for (int remx = 0; remx <= 1; remx++) {
	 	 	for (int remy = 0; remy <= 1; remy++) {
				for (int state = 0; state <= 2; state++) {
				 	if (dp[i][remx][remy][state] <= 0) continue;
				 	for (int digit = 0; digit <= 2; digit++) {
				 	 	int tempx = (remx + digit + digitx[i]);
				 	 	int tempy = (remy + digit + digity[i]);
				 	 	int bitx = tempx % 3;
				 	 	int bity = tempy % 3;
				 	 	if (bitx % 2 != bity % 2) continue;
				 	 	int new_state;
				 	 	if (state == 0) {
							if (digit > digitd[i]) {
							 	new_state = 2;
							} else {
							 	new_state = 0;
							}
				 	 	} else if (state == 1) {
				 	 	 	if (digit < digitd[i]) {
				 	 	 	 	new_state = 0;
				 	 	 	} else if (digit == digitd[i]) {
				 	 	 	 	new_state = 1;
				 	 	 	} else {
				 	 	 	 	new_state = 2;
				 	 	 	}
				 	 	} else {
				 	 	 	if (digit < digitd[i]) {
				 	 	 	 	new_state = 0;
				 	 	 	} else {
				 	 	 	 	new_state = 2;
				 	 	 	}
				 	 	}
				 	 	dp[i+1][tempx/3][tempy/3][new_state] += dp[i][remx][remy][state];
				 	}
				}
	 	 	}
	 	}
	}
	ll ret = 0ll;
	for (int state = 0; state <= 1; state++) {
	 	ret += dp[42][0][0][state];	
	}
	cout << ret << endl;
}

void solve(void) {
	cin >> q;
	for (int i = 1; i <= q; i++) {
	    ll x, y, d;
	    cin >> d >> x >> y;
	    cal_cows(x, y, d);
	}	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

