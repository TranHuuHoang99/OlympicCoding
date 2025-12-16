/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-16 09:20:25 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(void) {
	pair<int,int> one = {0,0};
	for (int i = 1; i <= 5; i++) {
	 	for (int j = 1; j <= 5; j++) {
			int val;
			cin >> val;
			if (val == 1) {
			 	one = {i,j};
			}
	 	}
	}
	int ret = abs(one.first - 3) + abs(one.second - 3);
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
 