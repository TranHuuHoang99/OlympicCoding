/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 26.12.2024 23:29:17
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
int n, k;

void solve(void) {
	cin >> n >> k;
	map<int,int> mp;
	for (int i = 0; i < n; i++) {
	 	int temp;
	 	cin >> temp;
	 	mp[temp]++;
	}
	vector<int> arr;
	for (auto it : mp) {
	 	if (it.second >= k) {
	 	 	arr.push_back(it.first);
	 	}
	}
	if (arr.empty()) {
	 	cout << -1 << endl;
	 	return;
	}
	sort(arr.begin(), arr.end());
	int left = arr[0], right = arr[0];
	int temp = arr[0];
	int len = 0;
	for (int i = 1; i < arr.size(); i++) {
	 	if (arr[i-1] == arr[i]-1) {
	 	 	if (arr[i]-temp > len) {
	 	 	 	left = temp;
	 	 	 	right = arr[i];
	 	 	 	len = arr[i]-temp;
	 	 	}
	 	} else {
	 	 	temp = arr[i];
	 	}
	}
	cout << left << ' ' << right << endl;
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
