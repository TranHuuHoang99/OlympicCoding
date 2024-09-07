#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 20+1;
const ll M = 1 << 20;
int n;
ll x;
ll w[N];

void solve(void) {
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> w[i];
	vector<pair<ll,ll>> dp((1 << n) + 1, {LLONG_MAX, LLONG_MAX});
	dp[0] = {1,0};

	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				int mask = i ^ (1 << j);
				if (dp[mask].second + w[j] <= x) {
					dp[i] = {dp[mask].first, min(dp[i].second, dp[mask].second + w[j])};
				} else {
					if (dp[mask].first + 1 <= dp[i].first) {
						dp[i] = {dp[mask].first + 1, min(dp[i].second, w[j])};
					}
				}
			}		
		}	
	}

	cout << dp[(1 << n) - 1].first << endl;
}
  
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
}
