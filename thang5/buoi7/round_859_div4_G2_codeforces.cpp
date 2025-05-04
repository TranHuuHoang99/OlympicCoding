#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
int A[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
	}
	sort(A+1,A+1+n);
	if (A[1] != 1) {
	 	cout << "NO" << endl;
	 	return;
	}
	ll temp = 1ll * A[1];
	for (int i = 2; i <= n; i++) {
	 	if (temp < A[i]) {
	 	 	cout << "NO" << endl;
	 	 	return;
	 	}
	 	temp += 1ll * A[i];
	}
	cout << "YES" << endl;
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

