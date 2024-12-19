/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 17.12.2024 19:50:55
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const ll N = 2e5+1;
int n, k;
ll A[N];
 
bool valid(ll a) {
 	int cnt = 1;
 	ll temp = 0;
 	for (int i = 1; i <= n; i++) {
		temp += A[i];
		if (temp > a) {
		 	temp = A[i];
		 	cnt++;
		}
 	}
 	return cnt <= k;
}
 
void solve(void) {
	cin >> n >> k;
	ll left = 0;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
	 	left = max(left, A[i]);
	}
	ll right = 1e18;
	ll ret = -1;
	while (left <= right) {
	 	ll mid = (right + left) / 2;
	 	if (valid(mid)) {
	 	 	ret = mid;
	 	 	right = mid - 1;
		} else {
		 	left = mid + 1;
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