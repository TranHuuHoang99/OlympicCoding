/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-08 10:05:00
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n;
int A[N], B[N];
int get_cost(int a, int b) {
 	return a == b ? 2 : 1;
}
void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cin >> B[i];
	int cur_val = get_cost(A[n], B[n]);
	for (int i = 1; i <= n-1; i++) {
	 	cur_val += get_cost(A[i], B[i+1]);
	 	cur_val += get_cost(A[i+1], B[i]);
	}
	int ret = cur_val;
	for (int i = 1; i <= n-1; i++) {
	 	cur_val -= get_cost(A[i], B[i+1]);
	 	cur_val += get_cost(A[i], B[i]);
	 	ret = max(ret, cur_val);
	}
	cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}






































