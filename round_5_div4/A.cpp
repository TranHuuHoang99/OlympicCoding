/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 27.02.2025 21:46:42
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const string cmp = "YES";

void solve(void) {
	string str;
	cin >> str;
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	if (str == cmp) {
	 	cout << "yes" << endl;
	} else {
	 	cout << "no" << endl;
	}
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
