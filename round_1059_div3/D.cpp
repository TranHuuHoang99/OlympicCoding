/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-26 20:03:04 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int ask(int type, int left, int right) {
 	cout << type << ' ' << left << ' ' << right << endl;
 	int ret;
 	cin >> ret;
 	return ret;
}
void solve(void) {
	cin >> n;
	int left = 1;
	int right = n;
	int l = 1;
	while (left <= right) {
	 	int mid = (left+right)>>1;
	 	int modify = ask(2, 1, mid);
	 	int origin = ask(1, 1, mid);
	 	if (modify == origin) {
	 	 	left = mid + 1;
	 	} else {
	 		l = mid;
	 	 	right = mid - 1;
	 	}
	}
	int diff = ask(2, 1, n) - ask(1, 1, n);
	int r = l + diff - 1;
	cout << '!' << ' ' << l << ' ' << r << endl;
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

