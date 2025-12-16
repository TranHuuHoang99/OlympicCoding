/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-16 10:37:06 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e3+10;
int A[N];
int n;
void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	int ret = 0;
	int min_val = A[1];
	int max_val = A[1];
	for (int i = 2; i <= n; i++) {
		if (A[i] > max_val) {
		 	ret++;
		 	max_val = A[i];
		}
		if (A[i] < min_val) {
		 	min_val = A[i];
		 	ret++;	
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
 