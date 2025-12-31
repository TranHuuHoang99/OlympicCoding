/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 25.02.2025 22:38:59
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
int n, x;

void solve(void) {
	cin >> n >> x;
	if (n == 1) {
	 	cout << x << endl;
	 	return;
	}
	vector<int> temp;
	temp.push_back(0);
	for (int i = 0; i < 30; i++) {
	 	if ((1<<i) & x) {
	 	 	temp.push_back(int(1<<i));
	 	}
	}
	vector<int> ret;
	for (int i = 0; i < temp.size(); i++) {
		int val = temp[i];
	 	for (int j = 0; j < temp.size(); j++) {
			val |= temp[j];
			ret.push_back(val);
			ret.push_back(temp[i] | temp[j]); 	 	 	
	 	}
	}
	sort(ret.begin(), ret.end());
	auto it = unique(ret.begin(), ret.end());
	ret.resize(distance(ret.begin(), it));
	while (ret.size() < n) {
	 	ret.push_back(0);
	}
	int check = 0;
	for (int i = 0; i < n; i++) check |= ret[i];
	if (check != x) ret[n-1] = x;
	for (int i = 0; i < n; i++) {
		cout << ret[i] << ' '; 	
	}
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
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}
