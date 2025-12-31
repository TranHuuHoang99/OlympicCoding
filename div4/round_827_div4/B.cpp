/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-11-13 15:33:41 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void solve(void) {
	cin >> n;
	set<int> save;
	for (int i = 1; i <= n; i++) {
	 	int temp;
	 	cin >> temp;
	 	save.insert(temp);
	}
	if (save.size() == n) {
	 	cout << "YES" << endl;
	} else {
	 	cout << "NO" << endl;
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
 