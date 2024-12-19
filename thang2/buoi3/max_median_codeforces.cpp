/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 17.12.2024 21:03:32
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
int A[N];
int update[N];
int sum[N];
int n, k;

bool valid(int mid) {
 	for (int i = 1; i <= n; i++) {
 	 	update[i] = A[i] >= mid ? 1 : -1;
 	}
	for (int i = 1; i <= n; i++) {
	 	sum[i] = sum[i-1] + update[i];
	}
	int min_val = INT32_MAX;
	for (int i = k; i <= n; i++) {
	 	min_val = min(min_val, sum[i-k]);
	 	if (sum[i] - min_val > 0) return true;
	}
	return false;
}

void solve(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
	}
	int left = 1;
	int right = 2e5;
	int ret = 0;
	while (left <= right) {
	 	int mid = (left + right) / 2;
	 	if (valid(mid)) {
	 	 	ret = mid;
	 	 	left = mid + 1;
	 	} else {
	 	 	right = mid - 1;
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
