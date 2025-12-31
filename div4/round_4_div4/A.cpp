/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 31.12.2024 21:00:30
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<int> arr;
	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);
	arr.push_back(d);
	sort(arr.begin(), arr.end());
	int idx = 0;
	for (int i = 0; i < 4; i++) {
	 	if (arr[i] == a) {
	 	 	idx = i+1;
	 	}
	}
	cout << (4-idx) << endl;
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
