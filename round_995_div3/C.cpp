/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 22.12.2024 22:41:05
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e5+1;
int A[N];
int n, m, k;

void solve(void) {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) cin >> A[i];
	set<int> s;
	for (int i = 1; i <= n; i++) s.insert(i);
	for (int i = 0; i < k; i++) {
	 	int temp;
	 	cin >> temp;
	 	auto it = s.find(temp);
	 	if (it != s.end()) s.erase(it);
	}
	string ret = "";
	for (int i = 0; i < m; i++) {
	 	int temp = -1;
	 	auto it = s.find(A[i]);
	 	if (it != s.end()) {
	 	 	temp = *it;
	 	 	s.erase(it);
	 	}
	 	if (s.empty()) {
	 	 	ret += '1';
	 	} else {
	 	 	ret += '0';
	 	}
	 	if (temp != -1) s.insert(temp);
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
