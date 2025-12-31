/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 05.12.2024 20:41:21
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

set<int> check;

void generate(void) {
 	for (int i = 1; i <= 99; i+=2) {
 	 	int temp = i*i;
 	 	check.insert(temp);
 	}
}

void solve(void) {
	int n;
	cin >> n;
	int ret = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
	 	int temp;
	 	cin >> temp;
	 	cnt += temp;
	 	auto it = check.find(cnt);
	 	if (it != check.end()) ret++;
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
	
	generate();

	int t;
	cin >> t;
	while (t--) {
	 	solve();
	}

	return 0;
}
