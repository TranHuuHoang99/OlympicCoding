#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	string str;
	cin >> str;
	set<int> s;
	for (int i = 0; i <= (int)str.size() - 4; i++) {
		if (str.substr(i, 4) == "1100") {
			s.insert(i);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		--a;
		str[a] = char('0'+b);
		for (int i = a-3; i <= a; i++) {
			if (i >= 0 && i <= str.size() - 4) {
				if (str.substr(i, 4) == "1100") {
					s.insert(i);
				} else {
					s.erase(i);
				}
			}
		}

		cout << (s.size() ? "YES" : "NO") << endl;
	}
}
  
int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}	

	return 0;
}



