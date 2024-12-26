/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 22.12.2024 21:37:02
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3;
int A[N], B[N];
int n;
int update[N];

void solve(void) {
	cin >> n;
	for (int i = 0; i <= 100; i++) {
	 	A[i] = 0;
	 	B[i] = 0;
	 	update[i] = 0;
	}
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cin >> B[i];
	for (int i = 1; i <= n; i++) {
	 	update[i] = A[i] - B[i+1];
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
	 	if (update[i] > 0) ret += update[i];
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
	while (t--) {
	 	solve();
	}

	return 0;
}
