/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2026-04-04 21:57:57 
************************************************************************** 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
void solve(void) {
	cin >> n;
	deque<int> dq;
	for (int i = 1; i <= 3*n; i++) dq.push_back(i);
	vector<int> ret;
	while (!dq.empty()) {
	 	int val1 = dq.front();
		dq.pop_front();
		int val3 = dq.back();
		dq.pop_back();
		int val2 = dq.back();
		dq.pop_back();
		ret.push_back(val1);
		ret.push_back(val2);
		ret.push_back(val3);
	}
	for (int r : ret) cout << r << ' ';
	cout << endl;
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
