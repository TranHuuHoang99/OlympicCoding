/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 25.03.2025 19:57:19
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e6+10;
ll m, n, s;
pair<ll,ll> A[12];
ll dis[N];

void solve(void) {
	cin >> m >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> A[i].first >> A[i].second;     	
	}
	for (int i = 0; i <= m; i++) dis[i] = -1;
	dis[s] = 0;
	queue<ll> q;
	q.push(s);
	while (!q.empty()) {
	 	ll temp = q.front();
	 	q.pop();
	 	for (int i = 1; i <= n; i++) {
	 	 	ll x, y;
	 	 	x = A[i].first;
	 	 	y = A[i].second;
	 	 	ll next = (temp*x + y) % m;
	 	 	if (dis[next] == -1) {
	 	 	 	dis[next] = dis[temp] + 1;
	 	 	 	q.push(next);
	 	 	}
	 	 	if (next == 0) {
	 	 	 	cout << dis[0] << endl;
	 	 	 	return;
	 	 	}
	 	}
	}
	cout << -1 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
