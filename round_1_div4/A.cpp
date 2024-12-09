/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 09.12.2024 19:32:32
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n;
	cin >> n;
	vector<int> ret;
	int a = 1;
	while (n > 0) {
		int temp = 1;
		if (n%10 != 0) {
		 	temp = n%10;
		 	temp *= a;
		 	ret.push_back(temp);
		}
		n /= 10;
		a *= 10;
	}
	cout << ret.size() << endl;
	for (int i = 0; i < ret.size(); i++) cout << ret[i] << ' ';
	cout << endl;
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
