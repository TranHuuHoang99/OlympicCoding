/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-16 15:19:11 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(void) {
	int x, y;
	cin >> x >> y;
	int len = abs(x) + abs(y);
	if (x > 0 && y > 0) {
	 	cout << 0 << ' ' << len <<  ' ' << len << ' ' << 0 << endl;
	} else if (x > 0 && y < 0) {
	 	cout << 0 << ' ' << -len << ' ' << len << ' ' << 0 << endl;
	} else if (x < 0 && y < 0) {
	 	cout << -len << ' ' << 0 << ' ' << 0 << ' ' << -len << endl;
	} else {
	 	cout << -len << ' ' << 0 << ' ' << 0 << ' ' << len << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
 