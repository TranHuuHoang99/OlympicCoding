/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-01 15:29:56 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n;
int A[N];
ll F[N][2];
void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= 1; j++) {
	 	 	F[i][j] = LLONG_MIN;
	 	}
	}
	F[1][0] = A[1];
	for (int i = 1; i < n; i++) {
	 	for (int j = 0; j <= 1; j++) {
	 	 	if (F[i][j] == LLONG_MIN) continue;
	 	 	if (j == 0) {
	 	 	 	F[i+1][0] = max(F[i+1][0], F[i][j] + A[i+1]);
	 	 	 	F[i+1][1] = max(F[i+1][1], F[i][j] - 2 * A[i] - A[i+1]);
	 		} else {
	 		 	F[i+1][0] = max(F[i+1][0], F[i][j] + A[i+1]);
	 		 	F[i+1][1] = max(F[i+1][1], F[i][j] + 2 * A[i] - A[i+1]);
	 		}
	 	}
	}
	ll ret = max(F[n][0], F[n][1]);
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
 