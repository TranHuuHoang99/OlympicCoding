/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2026-04-04 21:38:53 
************************************************************************** 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(void) {
	vector<int> save;
	for (int i = 1; i <= 7; i++) {
	 	int val;
		cin >> val;
		save.push_back(val);
	}
	sort(save.begin(), save.end());
	int sum = 0;
	for (int i = 0; i < 6; i++) sum += save[i] * (-1);
	sum += save[6];
	cout << sum << endl;
}
signed main(void) {
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
