/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 14.12.2024 14:32:11
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n, m;
	cin >> n >> m;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		arr[i] = str;
	}
	int ret = INT32_MAX;
	for (int i = 0; i < n; i++) {
	 	for (int j = i+1; j < n; j++) {
	 		int temp = 0;
	 		for (int k = 0; k < m; k++) {
	 		 	temp += abs(int(arr[i][k]-'a')-int(arr[j][k]-'a'));
	 		}
	 		ret = min(ret, temp);
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
