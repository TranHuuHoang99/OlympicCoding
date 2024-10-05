#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve(void) {
	int n;
	cin >> n;
	set<pair<int,int>> temp;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		temp.insert({a,b});
	}

	vector<pair<int,int>> path;
	vector<int> search;
	vector<bool> v(n, false);

	for (auto t : temp) {
		path.push_back(t);
		search.push_back(t.first);
	}

	pair<int,int> start;
	int a, b;
	cin >> a >> b;
	if (a - b <= 0) {
		cout << 0 << endl;
		return;
	} else {
		start = {a-b, 0};
	}

	int ret = 0;
	while (start.first > 0) {
		int pos = lower_bound(search.begin(), search.end(), start.first) - search.begin();
		if (pos == search.size()) {
			cout << -1 << endl;
			return;
		}

		int index = -1;
		int max_val = INT32_MIN;
		for (int i = pos; i < search.size(); i++) {
			if (!v[i] && max_val < path[i].second) {
				max_val = path[i].second;
				index = i;
			}	
		}

		if (index == -1) {
			cout << -1 << endl;
			return;
		} else {
			int get_val = start.first - path[index].second;
			ret++;
			v[index] = true;
			start = {get_val, 0};
		}	
	}

	cout << ret << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
