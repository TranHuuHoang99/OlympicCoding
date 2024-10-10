#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+1;
vector<int> ret;
vector<int> path[N];
int arr[N];
int n, m;

void solve(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		path[a].push_back(b);
		arr[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) if (!arr[i]) q.push(i);

	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		ret.push_back(temp);
		
		for (int next : path[temp]) {
			arr[next]--;
			if (!arr[next]) q.push(next);
		}
	}

	if (ret.size() != n) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		for (int i = 0; i < ret.size(); i++) cout << ret[i] << ' ';
		cout << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
}
