/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 13.12.2024 22:21:07
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n;
	cin >> n;
	string str;
	cin >> str;
	bool valid = true;
	for (int i = 0; i < n; i++) {
	 	int blue = 0, red = 0;
	 	if (str[i] != 'W') {
	 	 	while (i < n && str[i] != 'W') {
	 	 	 	if (str[i] == 'R') {
	 	 	 	 	red++;
	 	 	 	} else {
	 	 	 	 	blue++;
	 	 	 	}
	 	 	 	i++;
	 	 	}
	 	 	if (blue == 0 || red == 0) {
	 	 	 	valid = false;
	 	 	}
	 	}
	}
	cout << (valid ? "yes" : "no") << endl;
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
	while (t--) {
	 	solve();
	}

	return 0;
}
