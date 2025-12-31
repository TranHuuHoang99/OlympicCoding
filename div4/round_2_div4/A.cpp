/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 13.12.2024 21:42:32
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n;
	cin >> n;
	if (n <= 1399) {
	 	cout << "Division 4" << endl;
	 	return;
	}
	if (n >= 1400 && n <= 1599) {
	 	cout << "Division 3" << endl;
	 	return;
	}
	if (n >= 1600 && n <= 1899) {
	 	cout << "Division 2" << endl;
	 	return;
	}
	cout << "Division 1" << endl;
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
