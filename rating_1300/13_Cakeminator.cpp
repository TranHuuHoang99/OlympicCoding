/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-16 21:27:27 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 20;
int r, c;
int val[N][N];
char A[N][N];
void solve(void) {
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
	 	for (int j = 1; j <= c; j++) {
	 	 	cin >> A[i][j];
	 	}
	}
	int ret = 0;
	for (int i = 1; i <= r; i++) {
	 	bool isValid = true;
	 	for (int j = 1; j <= c; j++) {
	 	 	if (A[i][j] == 'S') {
	 	 	 	isValid = false;
	 	 	 	break;
	 	 	}
	 	}
	 	if (!isValid) continue;
	 	for (int j = 1; j <= c; j++) {
	 	 	val[i][j] = 1;
	 	}
	}
	for (int j = 1; j <= c; j++) {
	 	bool isValid = true;
	 	for (int i = 1; i <= r; i++) {
	 	 	if (A[i][j] == 'S') {
	 	 	 	isValid = false;
	 	 	 	break;
	 	 	}
	 	}
	 	if (!isValid) continue;
	 	for (int i = 1; i <= r; i++) val[i][j] = 1;
	}
	for (int i = 1; i <= r; i++) {
	 	for (int j = 1; j <= c; j++) {
	 	 	ret += val[i][j];
	 	}
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

