#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+1;
set<int> path[N];
bool v[N];
bool rs_v[N];
stack<int> st;
int n, m;

bool dfs(int cur) {
	v[cur] = true;
	rs_v[cur] = true;
	st.push(cur);
	for (int next : path[cur]) {
		if (!v[next]) {
			if (dfs(next)) return true;
		} 
		if (rs_v[next]) {
			st.push(next);
			return true;
		}
	}

	rs_v[cur] = false;
	st.pop();
	return false;
}

void solve(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		path[a].insert(b);
	}
	
	for (int i = 1; i <= n; i++) {
		if (!v[i] && dfs(i)) {
			vector<int> ret;
			int temp = st.top();
			st.pop();
			while (!st.empty()) {
				ret.push_back(st.top());
				st.pop();
				if (temp == ret.back() && st.size() != 1) break;
			}

			reverse(ret.begin(), ret.end());
			ret.push_back(temp);

			int idx = 0;
			for (int i = 0; i < ret.size(); i++) {
				if (ret[i] == temp) {
					idx = i;
					break;
				}
			}

			if (idx != 0) {
				idx--;
				ret.erase(ret.begin()+idx);
			}
			cout << ret.size() << endl;		
			for (int r : ret) cout << r << ' ';
			cout << endl;
			return;
		}
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
