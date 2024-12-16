/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 14.12.2024 14:01:18
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	string str;
	cin >> str;
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < 3; i++) {
	 	sum1 += int(str[i]-'0');
	}
	for (int i = 3; i < 6; i++) {
	 	sum2 += int(str[i]-'0');
	}
	cout << (sum1 == sum2 ? "yes" : "no") << endl;
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
