#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5;
int n, m, k;
vector<pair<int,ll>> path[N];

void solve(void) {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a,b;
		ll c;
		cin >> a >> b >> c;
		--a; --b;
		path[a].push_back({b,c});
	}

	vector<vector<ll>> update(n, vector<ll>(k, LLONG_MAX));
	update[0][0] = 0;
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
   	q.push({0,0});
	while (!q.empty()) {
		auto [val, cur] = q.top();
		q.pop();

		if (val > update[cur][k-1]) continue;
		int idx = 0;
		while (idx < k) {
			if (update[cur][idx] >= val) {
				update[cur][idx] = val;
				break;
			}
			idx++;
		}

		for (auto p : path[cur]) {
			for (int i = 0; i < k; i++) {
				if (update[p.first][i] > update[cur][idx] + p.second) {
					update[p.first][i] = update[cur][idx] + p.second;
					q.push({update[p.first][i], p.first});
					break;
				}
			}
		}
	}

	for (int i = 0; i < k; i++) cout << update[n-1][i] << ' ';
	cout << endl;	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
}
