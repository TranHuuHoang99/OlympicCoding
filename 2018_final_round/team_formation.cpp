/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-09 22:24:44 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
int n;
int A[N];
void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(A+1, A+1+n);
	int ret = 0;
	int max_val = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
	 	if (cnt >= max_val) {
	 	 	ret++;
	 	 	max_val = A[i];
	 	 	cnt = 0;
	 	}
	 	cnt++;
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

