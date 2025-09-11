/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-09 22:35:54 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
int n, k;
int A[N];
int sum1[N];
int sum2[N];
int F[N][15];

void solve(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];	
	}
	for (int i = 1; i <= n; i++) {
	 	sum1[i] = sum1[i-1] + A[i];
	 	sum2[i] = sum2[i-1] + A[i] * i;
	}
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= k; j++) {
	 	 	F[i][j] = INT32_MAX;
	 	}
	}
	F[0][0] = 0ll;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= k; j++) {
	 	 	for (int k = 1; k <= i; k++) {
	 	 	 	if (F[k-1][j-1] == INT32_MAX) continue;
	 	 	 	F[i][j] = min(F[i][j], F[k-1][j-1] + sum2[i] - sum2[k-1] - k * (sum1[i] - sum1[k-1]));
	 	 	}
	 	}
	}
	cout << F[n][k] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

