/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2026-03-31 09:02:10 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, s;
void solve(void) {
	cin >> n >> k >> s;
	if ((n-1) * k < s) {
	 	cout << "NO" << endl;
		return;
	}
	vector<int> save(k+1,0);
	int sum = 0;
	int i = 1;
	while (s != 0) {
		int min_val = min(n-1, s);
		s -= min_val;
		save[i] = min_val;
		i++;
	}
	int idx = k+1;
	for (int i = 1; i <= k; i++) {
		if (save[i] == 0) {
		 	idx = i;
		 	break;
		}
   	}
  	if (idx <= k) {
  		int temp = k-idx+1;
  	 	for (int i = idx-1; i >= 1; i--) {
			int min_val = min(save[i]-1, temp);
			save[i] -= min_val;
			temp -= min_val;
  	 	}
  	 	if (temp != 0) {
  	 	 	cout << "NO" << endl;
  	 	 	return;
  	 	}
  	 	for (int i = idx; i <= k; i++) {
  	 	 	save[i] = 1;
  	 	}
  	}
  	cout << "YES" << endl;
  	int cur = 1;
  	for (int i = 1; i <= k; i++) {
  		int next = cur + save[i];
  		if (next <= n) {
  		 	cout << next << ' ';
  		} else {
  		 	next -= 2 * save[i];
  		 	cout << next << ' ';
  		}
  		cur = next;
  	}
  	cout << endl;
}
signed main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
 