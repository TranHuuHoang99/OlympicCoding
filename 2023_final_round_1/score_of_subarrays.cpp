/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-14 11:11:42 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
const ll inf = 1e18;
int n;
ll A[N];
stack<pair<ll,ll>> st;

void solve(void) {
 	cin >> n;
 	for (int i = 0; i < n; i++) cin >> A[i];
 	A[n] = inf;
 	while (!st.empty()) st.pop();
 	ll ret = 0ll;
 	for (int i = 0; i <= n; i++) {
 	 	vector<vector<ll>> group;
 	 	while (!st.empty()) {
 	 	 	auto [idx,left] = st.top();
 	 	 	if (A[i] > A[idx]) {
 	 	 	 	st.pop();
 	 	 	 	if (i-idx > 1 && i != n) ret += 1ll * (i-idx+1);
 	 	 	 	if (idx-left > 1 && left != n) ret += 1ll * (idx-left+1);
 	 	 	 	if (!group.empty() && A[group.back().back()] == A[idx]) {
 	 	 	 	 	group.back().push_back(idx);
 	 	 	 	} else {
 	 	 	 	 	group.push_back({idx});
 	 	 	 	}
 	 	 	} else {
 	 	 	 	break;
 	 	 	}
 	 	}
 	 	for (vector<ll>& g : group) {
 	 	 	ll len = g.size();
 	 	 	reverse(g.begin(), g.end());
 	 	 	ret += 1ll * (len*(len-1)/2);
 	 	 	for (int j = 0; j < len; j++) {
 	 	 	 	ret += 1ll * (j - (len-1-j)) * g[j];
 	 	 	 	if (j > 0 && g[j] == g[j-1]+1) ret -= 2ll;
 	 	 	}
 	 	}
 	 	if (st.empty()) {
 	 	 	st.push({1ll * i, 1ll * n});
 	 	} else {
 	 	 	auto [idx,left] = st.top();
 	 	 	if (A[idx] > A[i]) {
 	 	 	 	st.push({1ll * i, 1ll * idx});
 	 	 	} else {
 	 	 	 	st.push({1ll * i, 1ll * left});
 	 	 	}
 	 	}
 	}
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

