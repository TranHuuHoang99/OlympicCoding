/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2026-04-05 12:37:45 
************************************************************************** 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
bool used[N];
int x, y;
void solve(void) {
	cin >> x >> y;
	int n = x + y;
	if (n % 2 == 0) {
	 	if (x < 1 || x > n/2) {
		 	cout << "NO" << endl;
			return;
		}
	} else {
	 	if (x > (n-1)/2) {
		 	cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	int k;
	if (n % 2 == 0) {
	 	k = x-1;
	} else {
		k = x;
	}
	for (int i = 1; i <= n; i++) used[i] = false;
	vector<int> even;
	int left = 2;
	int right = n;
	used[1] = true;
	while (k >= 1) {
	 	used[left] = true;
		used[right] = true;
		cout << left << ' ' << right << endl;
		even.push_back(left);
		left++;
		right--;
		k--;
	}
	for (int e : even) cout << 1 << ' ' << e << endl;
	for (int i = 1; i <= n; i++) {
		if (used[i]) continue;
		cout << 1 << ' ' << i << endl;
	}	
}
signed main(void) {
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


























































