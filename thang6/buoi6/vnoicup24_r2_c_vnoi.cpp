#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e5+10;
pair<ll,ll> AC[N];
ll prefixC[N], suffixC[N], prefixAC[N], suffixAC[N];
int n;

bool cmp(pair<ll,ll> a, pair<ll,ll> b) {
 	return a.first < b.first;
}

void solve(void) {
	cin >> n;
	for (int i = 0; i <= n+3; i++) {
	 	AC[i] = {0ll,0ll};
	 	prefixC[i] = 0ll;
	 	suffixC[i] = 0ll;
	 	prefixAC[i] = 0ll;
	 	suffixAC[i] = 0ll;
	}
	for (int i = 1; i <= n; i++) cin >> AC[i].first;
	for (int i = 1; i <= n; i++) cin >> AC[i].second;
	sort(AC+1, AC+1+n, cmp);
	for (int i = 1; i <= n; i++) {
	 	prefixC[i] = prefixC[i-1] + AC[i].second;
	 	prefixAC[i] = prefixAC[i-1] + AC[i].first * AC[i].second;
	}
	for (int i = n; i >= 1; i--) {
	 	suffixC[i] = suffixC[i+1] + AC[i].second;
	 	suffixAC[i] = suffixAC[i+1] + AC[i].first * AC[i].second;
	}
	if (prefixC[n] < 0) {
	 	cout << "-inf" << endl;
	 	return;
	}
	ll ret = LLONG_MAX;
	for (int i = 0; i <= n; i++) {
	 	ll temp = prefixC[i] - suffixC[i+1];
	 	if (temp <= 0) {
	 	 	ret = min(ret, temp * AC[i+1].first - prefixAC[i] + suffixAC[i+1]);
	 	} else {
	 	 	ret = min(ret, temp * AC[i].first - prefixAC[i] + suffixAC[i+1]);
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

