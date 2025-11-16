/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-11-13 15:37:20 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

char A[10][10];
bool check(char c) {
 	for (int i = 1; i <= 8; i++) {
		bool isValid = true;
		for (int j = 1; j <= 8; j++) {
		 	if (A[i][j] != c) {
		 	 	isValid = false;
		 	 	break;
		 	}
		}
		if (isValid) return true;
		for (int j = 1; j <= 8; j++) {
		 	if (A[j][i] != c) {
		 	 	break;
		 	}
		}
		if (isValid) return true;
 	}
 	return false;
}
void solve(void) {
	for (int i = 1; i <= 8; i++) {
	 	for (int j = 1; j <= 8; j++) {
	 	 	cin >> A[i][j];
	 	}
	}
	if (check('R')) {
	 	cout << 'R' << endl;
	 	return;
	} else {
	 	cout << 'B' << endl;
	 	return;
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
 