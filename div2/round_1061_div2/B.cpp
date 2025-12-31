/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-24 21:48:40 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, q;
string str;

void solve(void) {
	cin >> n >> q;
	cin >> str;
	bool isHalf = false;
	for (int i = 0; i < n; i++) {
	 	if (str[i] == 'B') {
	 	 	isHalf = true;
	 	 	break;
	 	}
	}
	for (int i = 1; i <= q; i++) {
		int a;
		cin >> a;
		if (!isHalf) {
		 	cout << a << "\n";
		 	continue;
		}
		int ret = 0;
		int idx = 0;
		while (a > 0) {
			if (str[idx] == 'A') {
			 	a--;
			} else {
			 	a /= 2;
			}
			ret++;
			idx++;
			idx %= n;
 		}
 		cout << ret << endl;
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


