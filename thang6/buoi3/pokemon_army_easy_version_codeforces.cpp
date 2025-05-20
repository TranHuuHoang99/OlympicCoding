#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e5+10;
int n, q;

void solve(void) {
	cin >> n >> q;
	vector<ll> A;
	vector<pair<int,int>> B;
	A.push_back(LLONG_MIN);
	for (int i = 1; i <= n; i++) {
	 	ll temp;
	 	cin >> temp;
	 	A.push_back(temp);
	}
	A.push_back(LLONG_MIN);
	ll ret = 0ll;
	for (int i = 1; i <= n; i++) {
	 	if (A[i] > A[i-1] && A[i] > A[i+1]) ret += A[i];
	 	if (A[i] < A[i-1] && A[i] < A[i+1]) ret -= A[i];
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

