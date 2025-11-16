/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-11-16 19:03:38 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(void) {
	int q;
	cin >> q;
	bool isOtherA = false;
	bool isOtherB = false;
	ll cnt1 = 0ll;
	ll cnt2 = 0ll;
	for (int i = 1; i <= q; i++) {
	 	int d, k;
	 	string str;
	 	cin >> d >> k >> str;
	 	for (char c : str) {
	 	 	if (d == 1) {
	 	 	 	if (c != 'a') {
	 	 	 	 	isOtherA = true;	
	 	 	 	} else {
	 	 	 	 	cnt1 += 1ll * k;
	 	 	 	}
	 	 	} else {
	 	 	 	if (c != 'a') {
					isOtherB = true;
	 	 	 	} else {
	 	 	 	 	cnt2 += 1ll * k;
	 	 	 	}
	 	 	}
 	 	}
 	 	if (isOtherB) {
 	 		cout << "YES" << "\n";	
 	 	} else if (!isOtherA && cnt1 < cnt2) {
 	 	 	cout << "YES" << "\n";
 	 	} else {
 	 	 	cout << "NO" << "\n";
 	 	}
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

