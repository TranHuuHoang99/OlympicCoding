#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int n, k;
bool dp[N];
int A[N];

void solve(void) {
 	cin >> n >> k;
 	for (int i = 1; i <= n; i++) cin >> A[i];
 	for (int i = 0; i <= k; i++) {
 	 	for (int j = 1; j <= n; j++) {
 	 	 	if (A[j] <= i && dp[i-A[j]] == false) {
 	 	 	 	dp[i] = true;
 	 	 	}
 	 	}
 	}
 	(dp[k]) ? cout << "First" : cout << "Second";
 	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

