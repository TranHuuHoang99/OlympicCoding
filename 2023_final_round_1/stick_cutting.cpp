/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-13 21:32:13 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e4+10;
int n, k, A, B;
int S[110];
ll F[110][N];

void solve(void) {
	cin >> n >> k >> A >> B;
	for (int i = 1; i <= n; i++) cin >> S[i];
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= 1e4; j++) {
	 	 	F[i][j] = LLONG_MAX;
	 	}
	}
	F[0][0] = 0ll;
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j <= 1e4; j++) {
	 	 	if (F[i][j] == LLONG_MAX) continue;
	 	 	if (S[i+1] == 1) {
	 	 	 	F[i+1][j+1] = F[i][j];
	 	 	 	continue;
	 	 	}
	 	 	F[i+1][j] = min(F[i+1][j], F[i][j]);
	 	 	if (j+S[i+1] > 1e4) continue;
	 	 	F[i+1][j+S[i+1]] = min(F[i+1][j+S[i+1]], F[i][j] + 1ll * A * (S[i+1]-1) * (S[i+1]-1) + B);
	 	}
	}
	ll ret = LLONG_MAX;
	for (int i = k; i <= 1e4; i++) ret = min(ret, F[n][i]);
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}

