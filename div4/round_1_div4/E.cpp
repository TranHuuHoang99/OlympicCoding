/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 10.12.2024 18:13:54
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n;
	cin >> n;
	vector<int> A(n+1);
	vector<int> update(9000);
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) {
		int temp = A[i];
	 	for (int j = i+1; j <= n; j++) {
			temp += A[j];
			if (temp <= n) update[temp]++;	 	 	
	 	}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
	 	ret += int(update[A[i]]>0);
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
