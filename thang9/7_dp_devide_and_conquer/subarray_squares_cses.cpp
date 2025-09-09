/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-09 21:35:24 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 3e3+10;
int n, k;
ll A[N];
ll sum[N];
ll F[N][N];

void compute(int left, int right, int optLeft, int optRight, int j) {
 	if (left > right) return;
 	int mid = (left+right)>>1;
 	ll best = LLONG_MAX;
 	int opt = -1;
 	for (int x = optLeft; x <= min(mid, optRight); x++) {
 		if (F[x-1][j-1] == LLONG_MAX) continue;
 	 	ll temp = sum[mid] - sum[x-1];
 	 	if (best > F[x-1][j-1] + temp * temp) {
 	 	 	best = F[x-1][j-1] + temp * temp;
 	 	 	opt = x;
 	 	}
 	}
 	F[mid][j] = best;
 	compute(left, mid-1, optLeft, opt, j);
 	compute(mid+1, right, opt, optRight, j);
}

void solve(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
	}
	for (int i = 1; i <= n; i++) {
	 	sum[i] = sum[i-1] + A[i];
	}
	for (int i = 0; i <= n; i++) F[i][0] = LLONG_MAX;
	F[0][0] = 0ll;
	for (int j = 1; j <= k; j++) {
	 	compute(1,n,1,n,j);
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

