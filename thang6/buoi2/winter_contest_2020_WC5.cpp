#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	string f, s, t;
	cin >> f >> s >> t;
	f.pop_back();
	t.pop_back();
	t.pop_back();
	string ret = f + t;
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}

