/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 23.01.2025 20:28:22
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e5+10;
int n;
int A[N], dp[N];

void solve(void) {
 	cin >> n;
 	for (int i = 1; i <= n; i++) cin >> A[i];
 	for (int i = 0; i <= n; i++) dp[i] = -1;
 	int ret = 0;
 	dp[0] = 0;
 	A[0] = INT32_MIN;
 	for (int i = 0; i < n; i++) {
 	 	if (A[dp[ret]] < A[i+1]) {
 	 	 	ret++;
 	 	 	dp[ret] = i+1;
 	 	} else {
 	 	 	int left = 1;
 	 	 	int right = ret-1;
 	 	 	int idx = 0;
 	 	 	int temp = A[i+1];
 	 	 	while (left <= right) {
 	 	 	 	int mid = (left+right) / 2;
 	 	 	 	if (A[dp[mid]] < temp) {
 	 	 	 	 	idx = mid;
 	 	 	 	 	left = mid + 1;
 	 	 	 	} else {
 	 	 	 	 	right = mid - 1;
 	 	 	 	}
 	 	 	}
 	 	 	if (A[dp[idx+1]] > temp) {
 	 	 	 	dp[idx+1] = i+1;
 	 	 	}
 	 	}
 	}
 	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
