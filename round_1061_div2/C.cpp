/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-24 22:58:13 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int cnt[N];
int sum[N];
int n, k;

void solve(void) {
	cin >> n >> k;
	memset(cnt, 0, sizeof(cnt));
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= n; i++) {
	 	int a;
	 	cin >> a;
	 	cnt[a]++;
	}
	for (int i = 1; i <= n; i++) {
	 	sum[i] = sum[i-1] + cnt[i];
	}
	int ret = 1;
	for (int i = 1; i <= n; i++) {
		int min_val = min(n, 4*i-1);
		int keep = sum[n] - sum[min_val];
		if (i <= n) keep += cnt[i];
		if (i*2 <= n) keep += cnt[i*2];
		if (i*3 <= n) keep += cnt[i*3];
		if (keep >= n-k) ret = i;
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


