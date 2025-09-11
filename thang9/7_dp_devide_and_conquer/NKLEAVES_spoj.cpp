/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-11 21:56:36 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
int n, k;
ll sum1[N];
ll sum2[N];
ll F[N][15];

ll cost(int left, int right) {
 	ll ret = sum2[right] - sum2[left];
 	ret -= (sum1[right] - sum1[left]) * 1ll * left;
 	return ret;
}

void compute(int left, int right, int optLeft, int optRight, int j) {
 	if (left > right) return;
 	int mid = (left+right)>>1;
 	ll best = LLONG_MAX;
 	int opt = -1;
 	for (int i = optLeft; i <= min(mid, optRight); i++) {
 		if (F[i-1][j-1] == LLONG_MAX) continue;
 		ll value = cost(i,mid);
 	 	if (best > F[i-1][j-1] + value) {
 	 	 	best = F[i-1][j-1] + value;
 	 	 	opt = i;
 	 	}
 	}
 	F[mid][j] = best;
 	compute(left, mid-1, optLeft, opt, j);
 	compute(mid+1, right, opt, optRight, j);
}

void solve(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
	 	ll temp;
	 	cin >> temp;
	 	sum1[i] = sum1[i-1] + temp;
	 	sum2[i] = sum2[i-1] + temp * 1ll * i;
	}
	for (int i = 1; i <= n; i++) {
	 	F[i][1] = cost(1,i);
	}
	for (int j = 2; j <= k; j++) {
	 	compute(1, n, 1, n, j);
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

