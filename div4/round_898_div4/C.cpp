/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-12 14:48:53 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int val[12][12];
char A[12][12];
void init(void) {
 	for (int i = 1; i <= 10; i++) {
 	 	for (int j = 1; j <= 10; j++) {
 	 	 	if (i == 1 || j == 1 || i == 10 || j == 10) {
 	 	 	 	val[i][j] = 1;
 	 	 	 	continue;
 	 	 	}
 	 	 	if (i == 2 || j == 2 || i == 9 || j == 9) {
 	 	 	 	val[i][j] = 2;
 	 	 	 	continue;
 	 	 	}
 	 	 	if (i == 3 || j == 3 || i == 8 || j == 8) {
 	 	 	 	val[i][j] = 3;
 	 	 	 	continue;
 	 	 	}
 	 	 	if (i == 4 || j == 4 || i == 7 || j == 7) {
 	 	 	 	val[i][j] = 4;
 	 	 	 	continue;
 	 	 	}
 	 	 	if (i == 5 || j == 5 || i == 6 || j == 6) {
 	 	 	 	val[i][j] = 5;
 	 	 	}
 	 	}
 	}
}
void solve(void) {
	int ret = 0;
	for (int i = 1; i <= 10; i++) {
	 	for (int j = 1; j <= 10; j++) {
	 	 	char c;
	 	 	cin >> c;
	 	 	if (c == 'X') {
				ret += val[i][j];
	 	 	}
	 	}
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}
 