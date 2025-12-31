/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 05.12.2024 21:41:27
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n, m;
	cin >> n >> m;
	int ret = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
	 	string str;
	 	cin >> str;
	 	int temp = (int)str.size();
	 	cnt += temp;
	 	if (cnt <= m) {
	 	 	ret++;
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
