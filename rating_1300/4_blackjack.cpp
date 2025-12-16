/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-16 10:21:14 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int deck[15];
void init(void) {
	for (int i = 1; i <= 11; i++) {
	 	if (i == 10) continue;
	 	deck[i] = 4;
	}
	deck[10] = 4 * 4 - 1;
}
void solve(void) {
	init();
	int n;
	cin >> n;
	int idx = max(0, n-10);
	cout << deck[idx] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
 