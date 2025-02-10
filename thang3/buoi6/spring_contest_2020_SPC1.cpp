/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 05.02.2025 15:33:30
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
const ll M = 2e3+10;
int n, m;
int A[N], B[M];
int dp[M][M];
vector<int> pos[M];

void solve(void) {
 	cin >> n >> m;
 	for (int i = 0; i <= M; i++) pos[i].clear();
 	for (int i = 1; i <= n; i++) {
 	 	cin >> A[i];
 	 	pos[A[i]].push_back(i);
 	}
 	for (int i = 1; i <= m; i++) cin >> B[i];
 	for (int i = 0; i <= m; i++) {
 	 	for (int j = 0; j <= m; j++) {
 	 	 	dp[i][j] = INT32_MAX;
 	 	}
 	}
	dp[0][0] = 0;
	for (int i = 0; i < m; i++) {
	 	for (int j = 0; j <= i; j++) {
			if (dp[i][j] == INT32_MAX) continue;
			// skip next element in array B
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			// put B[i+1] into sub array
			int left = 0;
			int right = pos[B[i+1]].size() - 1;
			int idx = -1;
			while (left <= right) {
			 	int mid = (left+right) / 2;
			 	if (pos[B[i+1]][mid] > dp[i][j]) {
			 	 	idx = pos[B[i+1]][mid];
			 	 	right = mid - 1;
			 	} else {
			 	 	left = mid + 1;
			 	}
			}
			if (idx != -1) {
			 	dp[i+1][j+1] = min(dp[i+1][j+1], idx);
			}
	 	}
	}
	int ret = 0;
	for (int i = 0; i <= m; i++) {
	 	if (dp[m][i] != INT32_MAX) {
	 	 	ret = max(ret, i);
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
