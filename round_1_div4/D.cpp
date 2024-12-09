/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 09.12.2024 23:01:04
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+1;
int A[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	int sum1 = 0, sum2 = 0, l = 0, r = n-1, l_val = 0, r_val = 0;
	int moves = 0;
	bool flag = true;
	while (l <= r) {
		if (flag) {
		 	if (l_val <= r_val) {
		 	 	l_val += A[l];
		 	 	sum1 += A[l];
		 	 	l++;
			} else {
			 	r_val = 0;
			 	flag = false;
			 	moves++;
			}
		} else {
			if (r_val <= l_val) {
			 	r_val += A[r];
			 	sum2 += A[r];
			 	r--;
			} else {
			 	l_val = 0;
			 	flag = true;
			 	moves++;
			}
		}
	}
	moves++;
	cout << moves << ' ' << sum1 << ' ' << sum2 << endl;
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
