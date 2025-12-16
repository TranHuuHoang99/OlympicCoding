/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-16 15:00:44 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void solve(void) {
	cin >> n;
	double ret = 0.0f;
	for (int i = 1; i <= n; i++) {
	 	double val;
	 	cin >> val;
	 	ret += val;
	}
	ret = ret / (1.0f * n);
	cout << fixed << setprecision(12) << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
 