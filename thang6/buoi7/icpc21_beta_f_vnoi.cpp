#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e4+10;
int n, u, m;
int A[N];
int cnt[110];
bool dp[2][100*N];

void solve(void) {
 	cin >> n >> u >> m;
	int total = 0;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
	 	total += A[i];
	 	cnt[A[i]]++;
 	}
 	vector<int> save;
 	for (int i = 1; i <= 100; i++) {
 	 	if (cnt[i] > 0) {
 	 	 	int sz = 1;
 	 	 	while (cnt[i] >= sz) {
 	 	 	 	save.push_back(i * sz);
 	 	 	 	cnt[i] -= sz;
 	 	 	 	sz *= 2;
 	 	 	}
 	 	 	if (cnt[i] > 0) {
 	 	 	 	save.push_back(i * cnt[i]);
 	 	 	}
 	 	}
 	 	cnt[i] = 0;
 	}
 	n = save.size();
	for (int i = 0; i <= 1; i++) {
	 	for (int j = 0; j <= total; j++) dp[i][j] = false;
	}
	dp[0][0] = true;
	for (int i = 1; i <= n; i++) {
	 	int cur = i % 2;
	 	for (int j = 0; j <= total; j++) dp[cur][j] = false;
	 	for (int j = 0; j <= total; j++) {
	 	 	dp[cur][j] = dp[!cur][j];
	 	 	if (j - save[i-1] >= 0) {
	 	 	 	dp[cur][j] = dp[cur][j] | dp[!cur][j-save[i-1]];
	 	 	}
	 	}
	}
	int ret = INT32_MAX;
	for (int i = 0; i <= total; i++) {
	 	if (dp[n%2][i]) {
	 	 	ret = min(ret, max((i+u-1)/u, (total-i+m-1)/m));
	 	 	ret = min(ret, max((i+m-1)/m, (total-i+u-1)/u));
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

