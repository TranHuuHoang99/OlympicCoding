#include <bits/stdc++.h>
#define ll long long

using namespace std;

int A[60];
int n;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(A+1, A+1+n);
	int min_val = A[1];
	int max_val = A[n];
	int ret = INT32_MAX;
	for (int i = 1; i <= n; i++) {
	 	if ((max_val + A[i]) % 2 == 0) {
	 	 	ret = min(ret, i-1);
	 	 	break;
	 	}
	}
	for (int i = n; i >= 1; i--) {
	 	if ((min_val + A[i]) % 2 == 0) {
	 	 	ret = min(ret, n - i);
	 	 	break;
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
 