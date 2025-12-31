/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 09.01.2025 22:06:16
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int v[11];
int n;

void solve(void) {
	memset(v,0,sizeof(v));
	cin >> n;
	vector<int> temp_arr;
	for (int i = 0; i < n; i++) {
	 	int temp;
	 	cin >> temp;
	 	temp_arr.push_back((temp%10));
	}
	vector<int> arr;
	for (int i = 0; i < temp_arr.size(); i++) {
	 	if (v[temp_arr[i]] <= 3) {
	 	 	arr.push_back(temp_arr[i]);
	 	 	v[temp_arr[i]]++;
	 	}
	}
	int len = arr.size();
	for (int i = 0; i < len; i++) {
	 	for (int j = i+1; j < len; j++) {
	 	 	for (int k = j+1; k < len; k++) {
	 	 	 	int sum = arr[i] + arr[j] + arr[k];
	 	 	 	if (sum % 10 == 3) {
	 	 	 	 	cout << "yes" << endl;
	 	 	 	 	return;
	 	 	 	}
	 	 	}
	 	}
	}
	cout << "no" << endl;
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
