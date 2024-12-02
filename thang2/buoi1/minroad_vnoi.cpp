/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 03.12.2024 20:02:55
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e5+1;
pair<ll,int> A[N];
int n, a, b;

bool cmp(pair<ll,int> ai, pair<ll,int> bi) {
 	return ai.first < bi.first;
}

void solve(void) {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
	 	ll d;
	 	int t;
	 	cin >> d >> t;
	 	A[i] = {d,t};
	}
	sort(A+1, A+1+n, cmp);
	ll ret = LLONG_MAX;
	pair<int,int> update = {0,0};
	int j = 0;
	for (int i = 1; i <= n; i++) {
	 	if (A[i].second == 1) {
	 	 	update.first++;
	 	} else {
	 	 	update.second++;
	 	}
	 	while (update.first >= a && update.second >= b) {
	 	 	ret = min(ret, A[i].first - A[j].first);
	 	 	if (A[j].second == 1) {
				update.first--;
	 	 	} else if (A[j].second == 2) {
	 	 	 	update.second--;
	 	 	}
	 	 	j++;
	 	}
	}
	if (ret == LLONG_MAX) {
	 	cout << -1 << endl;
	 	return;
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG
                   
	solve();

	return 0;
}
