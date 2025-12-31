/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-11-17 20:57:56 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int A[N];
int n;
void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
	}
	sort(A+1, A+1+n);
	int ret = 0;
	for (int i = 1; i <= n; i+=2) {
	 	ret = max(ret, A[i+1]-A[i]);
	}
	cout << ret << endl;
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

