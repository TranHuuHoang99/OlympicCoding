#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
int n, k;
int A[N];

void solve(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
	}
	int ret = 0;
	for (int i = 30; i >= 0; i--) {
	 	int cnt = 0;
	 	for (int j = 1; j <= n; j++) {
	 	 	if (!(A[j] & (1 << i))) cnt++;
	 	}
	 	if (cnt <= k) {
	 	 	ret += (1 << i);
	 	 	k -= cnt;
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

