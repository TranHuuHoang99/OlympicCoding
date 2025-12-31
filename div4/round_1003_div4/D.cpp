/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 21.02.2025 20:57:51
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m;

void solve(void) {
	cin >> n >> m;
	vector<vector<ll>> A(n, vector<ll>(m,0));
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < m; j++) {
	 	 	cin >> A[i][j];
	 	}
	}
	vector<ll> sum(n);
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < m; j++) {
	 	 	sum[i] += A[i][j];
	 	}
	}
	vector<int> temp(n);
	iota(temp.begin(), temp.end(), 0);
	sort(temp.begin(), temp.end(), [&] (int a, int b) -> bool {
		return sum[a] > sum[b];	 	
	});
	ll ret = 0;
	for (int i = 0; i < n; i++) {
		ret += sum[temp[i]] * (n-1-i) * m;
	}
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < m; j++) {
	 	 	 ret += A[i][j] * (m-j);
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
