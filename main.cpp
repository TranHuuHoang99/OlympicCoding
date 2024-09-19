#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+1;
int ret[N];
int n, m;
map<int,set<int>> mp;

void solve(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		mp[a].insert(b);
		mp[b].insert(a);
	}

	queue<int> q;	
	for (int i = 1; i <= n; i++) {
		if (ret[i] != 0) continue;
		ret[i] = 1;
		q.push(i);

		while (!q.empty()) {
			int temp = q.front();
			q.pop();

			for (auto s : mp[temp]) {
				if (ret[s] != 0 && ret[s] == ret[temp]) {
					cout << "IMPOSSIBLE" << endl;
					return;
				}

				if (ret[s] == 0) {
					ret[s] = ret[temp] == 1 ? 2 : 1;
					q.push(s);
				}
			}
		}
	}	

	for (int i = 1; i <= n; i++) cout << ret[i] << ' ';
   	cout << '\n';	
}
  
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
}
