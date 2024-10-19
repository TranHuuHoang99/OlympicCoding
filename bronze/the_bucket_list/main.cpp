#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+1;
int update[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		for (int j = x; j <= y; j++) update[j] += z;
	}

	int ret = n;
	for (int i = 0; i <= N; i++) ret = max(ret, update[i]);

	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);

	solve();

	return 0;
}	



