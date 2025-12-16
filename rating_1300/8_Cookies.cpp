/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-16 10:49:05 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(void) {
	int n;
	cin >> n;
	int sum_odd = 0;
	int sum_even = 0;
	int cnt_odd = 0;
	int cnt_even = 0;
	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		if (val % 2 == 0) {
		 	sum_even += val;
		 	cnt_even++;
		} else {
		 	sum_odd += val;
		 	cnt_odd++;
        }            
	}
	if (sum_odd % 2 == 0) {
		cout << cnt_even << endl;
	} else {
	 	cout << cnt_odd << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
 