#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 5e3+10;
int n;
ll x;

void solve(void) {
	cin >> n >> x;
	vector<ll> A(n+1);
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(A.begin()+1, A.end());
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
	 	if (x >= A[i]) {
	 	 	cnt++;
	 	 	x = x / i * 1ll * (i+1);
	 	} else {
	 	 	break;
	 	}
	}
	cout << cnt << endl;
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

