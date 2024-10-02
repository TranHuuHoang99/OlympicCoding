#include <bits/stdc++.h>
#define ll long long

using namespace std;
 
const ll N = 2500;
bool v_s[N];
bool v_e[N];
vector<int> btoe[N];
vector<int> etob[N];
int n, m;

void bfs(vector<int> arr[], int a, bool v[]) {	
	queue<int> q;
	q.push(a);
	v[a] = true;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int next : arr[temp]) {
			if (!v[next]) {
				q.push(next);
				v[next] = true;
			}
		}
	}
}

void solve(void) {
	cin >> n >> m;
	vector<tuple<int,int,ll>> tp(m);
	for (int i = 0; i < m; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		--a; --b;
		tp[i] = {a,b,-c};
		btoe[a].push_back(b);
		etob[b].push_back(a);
	}

	bfs(btoe, 0, v_s);
	bfs(etob, n-1, v_e);

	vector<ll> update(n, LLONG_MAX);
	update[0] = 0;
	// bellman-ford
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m; j++) {
			int a, b;
			ll c;
			tie(a,b,c) = tp[j];
			if (update[a] == LLONG_MAX) continue;
			update[b] = min(update[b], update[a] + c);
		}
	}

	vector<ll> temp_u = update;
	for (int i = 0; i < m; i++) {
		int a, b;
		ll c;
		tie(a, b, c) = tp[i];
		if (update[a] == LLONG_MAX) continue;
		update[b] = min(update[b], update[a] + c);
	}

	for (int i = 0; i < n; i++) {
		if (update[i] != temp_u[i] && v_s[i] && v_e[i]) {
			cout << -1 << endl;
			return;
		}
	}

	cout << -update[n-1] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
}




















