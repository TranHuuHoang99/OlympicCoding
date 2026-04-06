/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2026-04-04 23:46:28 
************************************************************************** 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(void) {
	int n;
	cin >> n;
	vector<int> save(n);
	for (int i = 0; i < n; i++) cin >> save[i];
	int ret = 0;
	for (int i = 0; i < n; i++) {
	 	for (int j = i+1; j < n; j++) {
		 	ret = max(ret, save[i] ^ save[j]);
		}
	}
	cout << ret << endl;
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
