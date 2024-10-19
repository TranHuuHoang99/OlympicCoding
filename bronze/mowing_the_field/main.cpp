#include <bits/stdc++.h>

using namespace std;

void solve(void) {
	int n;
	cin >> n;
	map<pair<int,int>, int> m;
	int t = 0, x = 0, y = 0;
	int ret = INT32_MAX;

	for (int i = 0; i < n; i++) {
		string a;
		int b;
		cin >> a >> b;
		for (int j = 0; j < b; j++) {
			t++;
			if (a == "N") {
				y++;
			} else if (a == "S") {
				y--;
			} else if (a == "W") {
				x--;
			} else {
				x++;
			}

			if (m.find({x,y}) != m.end()) {
				ret = min(ret, t - m[{x,y}]);
			}
			m[{x,y}] = t;
		}
	}

	ret = ret == INT32_MAX ? -1 : ret;
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);

	solve();

	return 0;
}

