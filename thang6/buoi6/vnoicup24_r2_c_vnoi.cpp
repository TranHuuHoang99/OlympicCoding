#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e5+10;
ll A[N], C[N];
ll sumA[N];
ll sumC[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cin >> C[i];
	for (int i = 1; i <= n; i++) {
	 	sumA[i] = sumA[i-1] + A[i];
	 	sumC[i] = sumC[i-1] + C[i];
	}

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

