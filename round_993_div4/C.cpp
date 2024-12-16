/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 15.12.2024 21:34:22
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int m, a, b, c;
	cin >> m >> a >> b >> c;
	int temp1 = min(m,a);
	int temp2 = min(m,b);
	int temp3 = m - temp1 + m - temp2;
	int temp4 = min(c,temp3);
	int ret = temp1 + temp2 + temp4;
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
