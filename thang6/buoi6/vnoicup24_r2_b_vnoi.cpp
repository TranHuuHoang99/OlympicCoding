#include <bits/stdc++.h>
#define ll long long

using namespace std;

int A[60];
int n;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	vector<pair<int,int>> ret;
	for (int i = 1; i <= n; i++) {
	 	if (i == A[i]) continue;
	 	int idx = -1;
	 	for (int j = i; j <= n; j++) {
	 	 	if (i == A[j]) {
	 	 	 	idx = j;
	 	 	 	break;
	 	 	}
	 	}
	 	ret.push_back({idx,n+1});
	 	for (int j = idx-1; j >= i; j--) {
	 	 	ret.push_back({j,j+1});
	 	 	A[j+1] = A[j];
	 	}
	 	ret.push_back({n+1, i});
	}
	cout << ret.size() << endl;
	for (int i = 0; i < ret.size(); i++) {
	 	cout << ret[i].first << ' ' << ret[i].second << endl;
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

