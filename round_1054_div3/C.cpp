/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-11-17 21:02:43 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int save[N];
int n, k;
void solve(void) {
	cin >> n >> k;
	int cnt = 0;
	memset(save, 0, sizeof(save));
	for (int i = 1; i <= n; i++) {
	 	int temp;
	 	cin >> temp;
	 	if (temp == k) cnt++;
	 	if (temp < k) save[temp]++;
	}
	int ret = 0;
	for (int i = 0; i < k; i++) {
	 	if (save[i] == 0) ret++;
	}
	cout << max(ret, cnt) << endl;
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

