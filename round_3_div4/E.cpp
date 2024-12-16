/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 15.12.2024 20:52:00
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
int A[N];
int update[N];
int n, q;

bool cmp(int a, int b) {
 	return a > b;
}

void solve(void) {
	memset(A,0,sizeof(A));
	memset(update,0,sizeof(update));
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(A+1,A+n+1,cmp);
	for (int i = 1; i <= n; i++) {
	 	update[i] = update[i-1] + A[i];
	}
	while (q--) {
		int x;
		cin >> x;
	 	int left = 1, right = n;
	 	int ret = INT32_MAX;
	 	while (left <= right) {
			int mid = (right+left)/2;
			if (update[mid] >= x) {
			 	ret = min(ret, mid);
			 	right = mid - 1;
			} else {
			 	left = mid + 1;
			}
	 	}
	 	cout << (ret == INT32_MAX ? -1 : ret) << endl;
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
