#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int x, y;
	cin >> x >> y;
	if (x == y) {
		cout << 0 << endl;
		return;
	}

	int ret = 0;
	int prev = x;
	int alpha = 1;

	while (true) {
		int update = x + alpha;
		if (update >= y && x < y || update <= y && x > y) {
			ret += abs(update-prev);
			ret -= abs(y-update);
			break;
		}

		ret += abs(update-prev);
		prev = update;
		alpha *= -2;
	}

	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);

	solve();

	return 0;
}	


