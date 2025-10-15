/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-09 20:07:52 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[6];
int ret[6];

void solve(void) {
	for (int i = 1; i <= 5; i++) cin >> A[i];
	for (int i = 5; i >= 1; i--) {
	 	for (int j = 5; j >= 1; j--) {
	 	 	if (ret[j] <= 0) continue;
	 	 	for (int k = (5-j)/i; k >= 1; k--) {
	 	 		int val = min(A[i]/k, ret[j]);
	 	 		ret[i*k+j] += val;
	 	 		A[i] -= val*k;
	 	 		ret[j] -= val;
	 	 	}
	 	}
	 	for (int j = 5/i; j >= 1; j--) {
	 	 	int val = A[i]/j;
	 	 	ret[i*j] += val;
	 	 	A[i] -=  val * j;
	 	}
	}
	cout << ret[1] + ret[2] + ret[3] + ret[4] + ret[5] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

