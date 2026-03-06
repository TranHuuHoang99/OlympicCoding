/*
**************************************************************************
	author     : hoangprodn
	email  	   : thhoang08091999@gmail.com
	local time : 2026-03-06 22:01:38
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
void solve(void) {
	cin >> n >> m;
	vector<int> D(n,0), C(m,0);
	for (int i = 0; i < n; i++) cin >> D[i];
	for (int i = 0; i < m; i++) cin >> C[i];
	sort(D.begin(), D.end(), greater<int>());
	int cutOff = 5e5+1;
	int j = 0;
	for (int i = 0; i < m; i++) {
		int target = C[i] - i;
		if (target >= cutOff) {
			cout << 0 << '\n';
			continue;
		}
		int ret = j * (cutOff - target);
		while (j < n && D[j] > target) {
			ret += D[j] - target;
			j++;
		}
		cout << ret << '\n';
		cutOff = target;
	}
}

signed main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}





