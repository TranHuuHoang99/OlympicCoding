/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 31.03.2025 23:30:15
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
ll A[N], x;
int n;

void solve(void) {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(A+1,A+n+1);
	reverse(A+1,A+n+1);
	int ret = 0;
	for (int i = 1, cnt = 1; i <= n; i++, cnt++) {
	 	if (A[i] * 1ll * cnt >= x) {
	 	 	ret++;
	 	 	cnt = 0;
	 	}
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}
