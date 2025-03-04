/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 25.02.2025 22:12:09
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n;
	string str;
	cin >> n >> str;
	int up = 0;
	int down = 0;
	for (int i = 0; i < str.size(); i++) {
	 	if (str[i] == '-') {
	 	 	up++;
	 	} else {
	 	 	down++;
	 	}
	}
	ll temp = 1ll * up / 2;
	if (up % 2 == 0) {
	 	temp = temp * temp;
	} else {
	 	temp = temp * (temp+1);
	}
	ll ret = 1ll * down * temp;
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
