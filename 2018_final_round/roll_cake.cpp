/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-09 20:48:22 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e3+10;
int A[N];
int n, m;

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(A+1, A+1+n);
	int ret = 0;
	for (int i = 1; i <= n; i++) {
	 	if (A[i] % 10 == 0) {
	 	 	while (A[i] > 10 && m > 0) {
	 	 	 	ret++;
	 	 	 	A[i] -= 10;
	 	 	 	m--;
	 	 	}
	 	 	if (A[i] == 10) ret++; // in case m < 0 and A[i] is 10
	 	}
	}
	for (int i = 1; i <= n && m > 0; i++) {
		while (A[i] > 10 && m > 0) {
		 	ret++;
		 	A[i] -= 10;
		 	m--;
		}
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

