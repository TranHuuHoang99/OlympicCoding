/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-11-25 20:25:13 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n;
int A[N];
ll one[N];
ll zero[N];
void solve(void) {
	cin >> n;
	memset(one, 0, sizeof(one));
	memset(zero, 0, sizeof(zero));
	memset(A, 0, sizeof(A));
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) {
	 	one[i] = one[i-1] + int(A[i] == 1);
	}
	for (int i = n; i >= 1; i--) {
	 	zero[i] = zero[i+1] + int(A[i] == 0);
	}
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
	 	if (A[i] == 1) {
	 	 	cnt += zero[i+1];
	 	}
	}
	ll ret = cnt;
	for (int i = 1; i <= n; i++) {
	 	if (A[i] == 1) {
	 	 	ll temp = cnt;
	 	 	temp -= zero[i+1];
	 	 	temp += one[i-1];
	 	 	ret = max(ret, temp);
	 	} else {
	 	 	ll temp = cnt;
	 	 	temp -= one[i-1];
	 	 	temp += zero[i+1];
	 	 	ret = max(ret, temp);
	 	}
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

