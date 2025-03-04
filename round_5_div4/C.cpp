/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 27.02.2025 22:03:14
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 110;
int A[N], n;
int ret[N];

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) {
	 	int len;
	 	string str;
	 	cin >> len >> str;
	 	int val = A[i];
	 	for (int j = 0; j < len; j++) {
	 	 	if (str[j] == 'D') {
	 	 	 	val++;
	 	 	 	if (val > 9) val = 0;
	 	 	} else {
	 	 	 	val--;
	 	 	 	if (val < 0) val = 9;
	 	 	}
	 	}
	 	ret[i] = val;
	}
	for (int i = 0; i < n; i++) cout << ret[i] << ' ';
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
