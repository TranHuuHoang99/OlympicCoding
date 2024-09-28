#include <bits/stdc++.h>
#define ll long long

using namespace std;
 
const ll N = 500 + 1;
int n, m, q;

void solve(void) {
	cin >> n >> m >> q;
	vector<vector<ll>> update(n+1, vector<ll>(n+1, LLONG_MAX));
	for (int i = 0; i < m; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		update[a][b] = min(update[a][b], c);
		update[b][a] = min(update[b][a], c);
	}

	for (int i = 1; i <= n; i++) update[i][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (update[j][i] == LLONG_MAX || update[i][k] == LLONG_MAX) continue;
				update[j][k] = min(update[j][k], update[j][i] + update[i][k]);
			}
		}
	}
	
	while (q--) {
		int a, b;
		cin >> a >> b;
		if (update[a][b] == LLONG_MAX) {
			cout << -1 << endl;
		} else {
			cout << update[a][b] << endl;
		}
	}		
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
}
