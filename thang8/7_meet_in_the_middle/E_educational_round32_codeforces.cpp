/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-01 20:56:39 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[40];
int n, MOD;
set<int> s;
vector<int> arr;

void solve(void) {
	cin >> n >> MOD;
	for (int i = 0; i < n; i++) {
	 	cin >> A[i];
	}
	int half = n/2;
	int len1 = (1 << half);
	int len2 = (1 << (n-half));
	int ret = 0;
	for (int mask = 0; mask < len1; mask++) {
		int sum = 0;
	 	for (int i = 0; i < half; i++) {
	 	 	if (mask & (1 << i)) {
	 	 		sum = (sum % MOD + A[i] % MOD) % MOD;
	 	 	}
	 	}
	 	s.insert(sum);
	 	ret = max(ret, sum);
	}
	for (int e : s) {
	 	arr.push_back(e);
	}
	for (int mask = 0; mask < len2; mask++) {
	 	int sum = 0;
	 	for (int i = half; i < n; i++) {
	 	 	if (mask & (1 << (i-half))) {
	 	 		sum = (sum % MOD + A[i] % MOD) % MOD;
	 	 	}
	 	}
	 	ret = max(ret, sum);
		int left = 0;
		int right = arr.size()-1;
		int idx = 0;
		while (left <= right) {
			int mid = (left+right)>>1;
			if (arr[mid] < MOD-sum) {
				idx = mid;
			 	left = mid + 1;
			} else {
			 	right = mid - 1;
			}
		}
		ret = max(ret, sum + arr[idx]);
		ret = max(ret, sum + arr.back() - MOD);
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

