#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5 + 1;
const ll M = 1e5 * 2 + 1;
int n, m;
bool v[N];
map<int,set<int>> mp;
int track[N];
int s_track = -1;
int e_track = -1;

bool dfs(int i, int p) {
	v[i] = true;
	track[i] = p;

	for (int next : mp[i]) {
		if (next == p) continue;
		if (!v[next]) {
			if (dfs(next, i)) return true;
		} else {	
			s_track = next;
			e_track = i;
			return true;
		}
	}

	return false;
}

void solve(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		mp[a].insert(b);
		mp[b].insert(a);
	}
	
	bool valid = false;
	for (int i = 1; i <= n; i++) {
		if (v[i]) continue;
		valid = dfs(i, -1);
		if (valid) break;
	}

	if (valid) {
		stack<int> st;
		queue<int> q;
		int temp = e_track;

		st.push(e_track);
		while (temp != s_track) {
			st.push(track[temp]);
			temp = track[temp];
		}
		st.push(e_track);

		cout << st.size() << endl;

		while (!st.empty()) {
			cout << st.top() << ' ';
			st.pop();
		}
		cout << '\n';

		return;
	}

	cout << "IMPOSSIBLE" << endl;
}
  
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();	

	return 0;
}
