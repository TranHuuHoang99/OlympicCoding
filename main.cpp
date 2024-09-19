#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5 + 1;
vector<pair<int,int>> graph(N, {0, INT32_MAX});
bool v[N];
int n, m;
map<int, set<int>> mp;

void solve(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		mp[a].insert(b);
		mp[b].insert(a);
	}

	queue<int> q;
	graph[1] = {1,1};
	for (int i = 1; i <= n; i++) {
		if (v[i] || graph[i].second == INT32_MAX) continue;
		q.push(i);
		v[i] = true;

		while (!q.empty()) {
			int temp = q.front();
			q.pop();
			
			for (auto s : mp[temp]) {
				if (graph[s].second > graph[temp].second + 1) {
					graph[s].second = graph[temp].second + 1;
					graph[s].first = temp;
				}

				if (!v[s]) {
					v[s] = true;
					q.push(s);
				}
			}
		}
	}

	if (graph[n].second == INT32_MAX) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		stack<int> ret;
		queue<int> n_q;
		n_q.push(n);
		
		while (!n_q.empty()) {
			int temp = n_q.front();
			n_q.pop();
			ret.push(temp);
			if (temp == 1) break;
			n_q.push(graph[temp].first);	
		}

		cout << graph[n].second << endl;
		while (!ret.empty()) {
			cout << ret.top() << ' ';
			ret.pop();
		}
		cout << '\n';
	}
}
  
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
}
