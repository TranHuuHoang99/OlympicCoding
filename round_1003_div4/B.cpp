/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 19.02.2025 20:58:36
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	string str;
	cin >> str;
	for (int i = 1; i < str.size(); i++) {
	 	if (str[i] == str[i-1]) {
	 	 	cout << 1 << endl;
	 	 	return;
	 	}
	}
	cout << str.size() << endl;
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
