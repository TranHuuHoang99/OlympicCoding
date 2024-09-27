#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+1;
int n, m;
vector<pair<ll,int>> arr[N];

void solve(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		arr[a].push_back({c,b});
	}

	vector<ll> update(n+1, LLONG_MAX);
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
	update[1] = 0;
	pq.push({0,1});

	while (!pq.empty()) {
		auto [x,y] = pq.top();
		pq.pop();

		if (x > update[y]) continue;
		
		for (pair<ll,int> p : arr[y]) {
			if (update[p.second] > update[y] + p.first) {
				update[p.second] = update[y] + p.first;
				pq.push({update[p.second], p.second});
			}
		}
	}

	for (int i = 1; i <= n; i++) cout << update[i] << ' ';
	cout << '\n';
}
  
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
}
