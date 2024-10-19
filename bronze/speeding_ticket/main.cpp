#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 100+1;
pair<int,int> limit[N];
pair<int,int> act[N];
int n, m;

void solve(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> limit[i].first >> limit[i].second;
	}

	for (int i = 0;  i < m; i++) {
		cin >> act[i].first >> act[i].second;
	}

	int check = 100;
	int i = 0;
	int j = 0;
	int ret = 0;
	while (check) {
		if (act[i].second > limit[j].second) {
			ret = max(ret, act[i].second - limit[j].second);
		}

		if (act[i].first > limit[j].first) {
			act[i].first -= limit[j].first;
			check -= limit[j].first;
			j++;
		} else if (act[i].first == limit[j].first) {
			check -= act[i].first;
			i++; j++;
		} else {
			check -= act[i].first;
			limit[j].first -= act[i].first;
			i++;
		}
	}

	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);

	solve();

	return 0;
}	


