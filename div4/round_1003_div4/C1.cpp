/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 21.02.2025 19:50:24
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
int n, m, A[N], B[N];

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= m; i++) cin >> B[i];
	int val = min(A[1], B[1]-A[1]);
	for (int i = 2; i <= n; i++) {
	 	if (A[i] >= val && B[1] - A[i] >= val) {
	 	 	val = min(A[i], B[1] - A[i]);
	 	} else if (A[i] >= val) {
	 	 	val = A[i];
	 	} else if (B[1] - A[i] >= val) {
	 	 	val = B[1] - A[i];
	 	} else {
	 	 	cout << "no" << endl;
	 	 	return;
	 	}
	}
	cout << "yes" << endl;
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
