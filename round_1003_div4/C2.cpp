/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 21.02.2025 20:02:40
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
int n, m;

void solve(void) {
	cin >> n >> m; 
	vector<int> A(n);
	vector<int> B(m);
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < m; i++) cin >> B[i];
	sort(B.begin(), B.end());
	int val = min(A[0], B[0] - A[0]);
	for (int i = 1; i < n; i++) {
	 	int temp = INT32_MAX;
	 	if (A[i] >= val) temp = A[i];
	 	int left = 0;
	 	int right = m-1;
	 	while (left <= right) {
	 	 	int mid = (left+right) / 2;
	 	 	if (B[mid] - A[i] >= val) {
	 	 	 	temp = min(temp, B[mid] - A[i]);
	 	 	 	right = mid - 1;
	 	 	} else {
	 	 	 	left = mid + 1;
	 	 	}
	 	}
	 	if (temp >= val && temp != INT32_MAX) {
	 	 	val = temp;
	 	} else {
	 	 	cout << "no" << endl;
	 	 	return;
	 	}
	}
	cout << "yes" << endl;
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
