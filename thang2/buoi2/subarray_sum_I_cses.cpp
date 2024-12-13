/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 13.12.2024 12:17:07
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
ll A[N];
ll update[N];
int n;
ll x;

void solve(void) {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) {
	 	update[i] = update[i-1] + A[i];
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
	 	int left = 0, right = i;
	 	ll temp = update[right] - x;
	 	while (left <= right) {
	 	 	int mid = left + (right-left) / 2;
	 		if (update[mid] == temp) {
	 		 	ret++;
	 		 	break;
	 	 	} else if (update[mid] < temp) {
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
	
	solve();

	return 0;
}
