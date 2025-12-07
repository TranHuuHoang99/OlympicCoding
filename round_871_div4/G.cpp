/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-08 09:00:13 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 3e3+10;
const ll M = 2e6+10;
ll F[N][N];
ll ans[M];
ll val = 1;
void init(void) {
	for (int i = 1; i < 1500; i++) {
	 	for (int j = i-1; j >= 1; j--) {
	 	 	F[j][i-j] = F[j-1][i-j] + F[j][i-j-1] - F[j-1][i-j-1] + val * val;
	 	 	ans[val] = F[j][i-j];
	 	 	val++;
	 	}
	}
}
void solve(void) {
	int n;
	cin >> n;
	cout << ans[n] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}
 