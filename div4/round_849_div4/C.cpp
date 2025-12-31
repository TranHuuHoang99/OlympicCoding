/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-01 11:32:07 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
string str;
void solve(void) {
	cin >> n;
	cin >> str;
	int left = 0;
	int right = n-1;
	int cnt = 0;
	while (left <= right) {
	 	if (str[left] != str[right]) {
	 	 	cnt += 2;
	 	 	left++;
	 	 	right--;
	 	} else {
	 	 	break;
	 	}
	}
	cout << n - cnt << endl;
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
 