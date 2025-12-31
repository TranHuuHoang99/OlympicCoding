/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-26 20:32:32 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k;
void solve(void) {
	cin >> n >> k;
	vector<int> A(n);
	vector<int> cnt(n+1);
	for (int i = 0; i < n; i++) {
	 	cin >> A[i];
	 	cnt[A[i]]++;
	}
	int x = -1;
	for (int i = 1; i <= n; i++) {
	 	if (cnt[i] == 0) {
	 	 	x = i;
	 	 	break;
	 	}
	}
	if (x == -1) {
	    for (int i = 0; i < k; i++) cout << A[i%3+n-3] << ' ';
	    cout << endl;
	    return;
	}	
	int temp = -1;
	for (int i = 1; i <= n; i++) {
	 	if (i != x && i != A[n-1]) {
	 	 	temp = i;
	 	 	break;
	 	}
	}
	vector<int> arr = {x, temp, A[n-1]};
	for (int i = 0; i < k; i++) cout << arr[i%3] << ' ';
	cout << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}

