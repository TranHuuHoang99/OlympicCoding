#include <bits/stdc++.h>
#define ll long long

using namespace std;

double e, w, s;

void solve(void) {
	cin >> e >> w >> s;
	double ret = e / s * w;
	cout << fixed << setprecision(6) << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

