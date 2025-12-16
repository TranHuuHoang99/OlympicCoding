/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-16 14:42:48 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void solve(void) {
	cin >> n;
	int power = n * n;
	int half = power / 2;
	int step = half / n;
	for (int i = 1; i <= half; i+=step) {
	 	for (int j = i; j < i+step; j++) {
	 	 	cout << j << ' ';
	 	}
	 	for (int j = i; j < i+step; j++) {
	 	 	cout << (power-j+1) << ' ';
	 	}
	 	cout << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
 