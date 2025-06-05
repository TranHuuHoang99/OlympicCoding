#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
int n, m;
ll B[N];
vector<pair<int,ll>> A[N];

void init(void) {
 	for (int i = 1; i <= n; i++) {
 	 	A[i].clear();
 	}
}

ll minBat(ll maxW) {
 	vector<ll> dp(n+1, LLONG_MIN);
 	dp[1] = min(maxW, B[1]);
 	for (int u = 1; u <= n; u++) {
 		if (dp[u] == LLONG_MIN) continue;
 	 	for (int i = 0; i < A[u].size(); i++) {
 	 	 	int v = A[u][i].first;
 	 	 	ll val = A[u][i].second;
			if (dp[u] >= val) {
			 	dp[v] = max(dp[v], min(maxW, dp[u] + B[v]));
 	 	 	}
 	 	}
 	}
 	return dp[n];
}

void solve(void) {
	cin >> n >> m;
	init();
	for (int i = 1; i <= n; i++) cin >> B[i];
	for (int i = 1; i <= m; i++) {
	 	int a, b;
	 	ll c;
	 	cin >> a >> b >> c;
	 	A[a].push_back({b,c});
	}
	ll left = 0ll;
	ll right = 1e9;
	ll ret = LLONG_MAX;
	while (left <= right) {
		ll mid = (left + right) / 2ll;
		ll min_val = minBat(mid);
		if (min_val != LLONG_MIN) {
			ret = min(ret, min_val);
		 	right = mid - 1ll;
		} else {
		    left = mid + 1ll;
		}	
	}
	if (ret == LLONG_MAX) {
	    cout << -1 << endl;
	} else {
	 	cout << ret << endl;
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
 