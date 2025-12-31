/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 31.12.2024 21:17:55
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n;
	cin >> n;
	vector<int> arr;
	set<int> s;
	for (int i = 0; i < n; i++) {
	 	int temp;
	 	cin >> temp;
	 	arr.push_back(temp);
	 	s.insert(temp);
	}
	int ret = arr.size() - s.size();
	if (ret % 2 == 0) {
	 	cout << s.size() << endl;
	} else {
	 	cout << (s.size() - 1) << endl;
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
	while (t--) {
	 	solve();
	}

	return 0;
}
