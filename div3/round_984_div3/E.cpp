#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, k, q;

void solve(void) {
	cin >> n >> k >> q;
	vector<vector<int>> A(k, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cin >> A[j][i];
			if (i > 0) A[j][i] |= A[j][i-1];
		}
	}

	while (q--) {
		int m;
		cin >> m;
		int high = n;
		int low = 0;
		for (int i = 0; i < m; i++) {
			int a, b;
			char c;
			cin >> a >> c >> b;
			--a;
			if (c == '<') {
				high = min(high, int(lower_bound(A[a].begin(), A[a].end(), b) - A[a].begin()));
			} else {
				low = max(low, int(upper_bound(A[a].begin(), A[a].end(), b) - A[a].begin()));
			}
		}
		cout << (low >= high ? -1 : low+1) << endl;
	}
}
  
int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}




