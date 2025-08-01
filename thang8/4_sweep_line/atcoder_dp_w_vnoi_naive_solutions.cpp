/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-07-30 21:29:49 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n, m;
vector<pair<int,ll>> line[N];
ll prefix[N];
ll A[N];
ll dp[N];

void solve(void) {
 	cin >> n >> m;
 	for (int i = 1; i <= m; i++) {
 	 	int left, right;
 	 	ll val;
 	 	cin >> left >> right >> val;
 	 	A[left] += val;
 	 	if (right + 1 <= n) A[right+1] -= val;
 	 	line[left].push_back({right,val});
 	}
 	for (int i = 1; i <= n; i++) {
 	 	prefix[i] = prefix[i-1] + A[i];
 	}
 	dp[0] = 0;
 	ll ret = 0ll;
 	for (int i = 1; i <= n; i++) {
 		// we set s[i] to be one and the previous character is all zero
 		ll cost = prefix[i];
 		dp[i] = cost;
 		// we set s[i] to be one and the previous character is one => so we have to substract it out of current cost	m
 		for (int j = 1; j < i; j++) {
 		 	for (auto [right, val] : line[j]) {
 		 		if (right >= i) {
 		 		 	cost -= val;
 		 		}
 		 	}
 		 	dp[i] = max(dp[i], dp[j] + cost);
 		}
 		ret = max(ret, dp[i]);
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
	solve();
	return 0;
}

