/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-26 16:52:30 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a, b;
void solve(void) {
	cin >> a >> b;
	if (__builtin_clz(a) > __builtin_clz(b)) {
	 	cout << -1 << endl;
	 	return;
	}
	if (b == a) {
	 	cout << 0 << endl;
	 	return;
	}
	vector<int> ret;
	for (int i = 0; i < 32; i++) {
		bool bita = (a & (1 << i));
		bool bitb = (b & (1 << i));
		if (bita != bitb) {
		 	ret.push_back((int)(1 << i));	
		}
	}
	cout << ret.size() << endl;
	for (int r : ret) cout << r << ' ';
	cout << endl;
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

