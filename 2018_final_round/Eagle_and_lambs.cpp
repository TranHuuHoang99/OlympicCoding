/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-10 09:24:30 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e3+10;
int n;
int A[N];
bool cmp(int a, int b) {
 	return a > b;
}
void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(A+1, A+1+n, cmp);
	int ret = 0;
	for (int i = 1; i <= n; i++) {
	 	ret += A[i];
	 	for (int j = i+1; j <= n; j++) {
	 	 	A[j] = max(A[j]-1, 0);
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

