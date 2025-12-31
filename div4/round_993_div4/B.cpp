/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 15.12.2024 21:34:13
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	string str;
	cin >> str;
	string ret = "";
	for (int i = str.size()-1; i >= 0; i--) {
	 	if (str[i] == 'q') {
	 	 	ret += 'p';
	 	} else if (str[i] == 'p') {
	 	 	ret += 'q';
	 	} else {
	 	 	ret += str[i];
	 	}
	}
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
	while (t--) {
	 	solve();
	}

	return 0;
}
