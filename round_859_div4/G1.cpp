                                                                                     /*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-04 22:10:13 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 5e3+10;
int A[N];
int n;
void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(A+1, A+1+n);
	int sum = 1;
	for (int i = 1; i <= n; i++) {
	 	if (sum < A[i]) {
	 	 	cout << "NO" << endl;
	 	 	return;
	 	}
	 	if (i == 1) continue;
	 	sum += A[i];
	}
	cout << "YES" << endl;
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

