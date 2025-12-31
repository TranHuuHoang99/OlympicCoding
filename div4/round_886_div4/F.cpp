/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-09 21:05:46 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n;
int A[N];
int ans[N];
void solve(void) {
	cin >> n;
	memset(A, 0, sizeof(A));
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= n; i++) {
	 	int val;
	 	cin >> val;
	 	if (val <= n) A[val]++;
	}
	for (int i = 1; i <= n; i++) {
	 	for (int j = i; j <= n; j+=i) {
			ans[j] += A[i];
	 	}
	}
	cout << *max_element(ans+1, ans+1+n) << endl;
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

