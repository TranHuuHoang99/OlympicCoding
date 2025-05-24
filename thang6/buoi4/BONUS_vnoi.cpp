#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+10;
int n, k;
int A[N][N];
int prefixSum[N][N];

void solve(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= n; j++) {
	 	 	cin >> A[i][j];
	 	}
	}
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= n; j++) {
	 	 	prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] + A[i][j] - prefixSum[i-1][j-1];
	 	}
	}
	int ret = 0;
	for (int i = k; i <= n; i++) {
	 	for (int j = k; j <= n; j++) {
	 	 	int temp = prefixSum[i][j] - prefixSum[i-k][j] - prefixSum[i][j-k] + prefixSum[i-k][j-k];
	 	 	ret = max(ret, temp);
	 	}
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

