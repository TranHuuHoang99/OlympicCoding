/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 14.12.2024 13:01:17
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
int A[N];
int prefix_sum[N];
int suffix_sum[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	memset(prefix_sum, 0, sizeof(prefix_sum));
	memset(suffix_sum, 0, sizeof(suffix_sum));
	for (int i = 1; i <= n; i++) {
	 	prefix_sum[i] = prefix_sum[i-1] + A[i];
	}
	for (int i = n; i >= 1; i--) {
	 	suffix_sum[i] = suffix_sum[i+1] + A[i];
	}
	int ret = 0;
	for (int i = n; i >= 2; i--) {
		int left = 1;
		int right = i - 1;
		int temp = suffix_sum[i];
		while (left <= right) {
		 	int mid = (left+right) /2;
		 	if (prefix_sum[mid] == temp) {
		 	 	ret = max(ret, mid + n + 1 - i);
		 	 	break;
		 	} else if (prefix_sum[mid] < temp) {
		 		left = mid + 1;	
			} else {
			 	right = mid - 1;
			}
		}
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
