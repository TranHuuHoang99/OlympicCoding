/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 09.01.2025 22:53:43
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
int A[N];
int update[N];
int temp[N];
int n, k;

void solve(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n-1; i++) {
		temp[i] = int((A[i] < 2 * A[i+1])); 	
	}
	for (int i = 1; i <= n-1; i++) {
	 	update[i]  = update[i-1] + temp[i];
	}
	int ret = 0;
	for (int i = k; i <= n-1; i++) {
	 	int sum = update[i] - update[i-k];
	 	if (sum == k) ret++;
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
	while (t--) {
	 	solve();
	}

	return 0;
}
