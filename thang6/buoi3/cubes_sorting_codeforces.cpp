#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 5e4+10;
int A[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	int temp = A[1];
	for (int i = 2; i <= n; i++) {
	 	if (temp > A[i]) {
	 	 	temp = A[i];
	 	} else {
	 	 	cout << "YES" << endl;
	 	 	return;
	 	}
	}
	cout << "NO" << endl;
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

