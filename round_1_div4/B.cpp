/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 09.12.2024 19:44:48
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n, k;
	cin >> n >> k;
	if (k > n) {
	 	cout << "NO" << endl;
	 	return;
	}
	if (k == 1) {
	 	cout << "YES" << endl;
	 	cout << n << endl;
	 	return;
	}
	if (n%k == 0) {
	    cout << "YES" << endl;
	    for (int i = 0; i < k; i++) cout << (n/k) << ' ';
	    cout << endl;
	} else {
		int temp1 = n/k;
		int remain = n - temp1*k;
		int temp2 = temp1 + remain;
		if ((temp1+temp2) % 2 == 0) {
		 	cout << "YES" << endl;
		 	for (int i = 0; i < k-1; i++) cout << temp1 << ' ';
		 	cout << temp2 << endl;
		} else {
		 	if ((k-1)%2 != 0) {
		 	 	cout << "NO" << endl;
		 	} else {
		 		if (temp1-1 <= 0) {
		 		 	cout << "NO" << endl;
		 		 	return;
		 		}
		 	 	cout << "YES" << endl;
		 	 	for (int i = 0; i < (k-1)/2; i++) cout << temp1 + 1 << ' ';
		 	 	for (int i = (k-1)/2; i < k-1; i++) cout << temp1 - 1 << ' ';
		 	 	cout << temp2 << endl;
		 	}
		}
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
