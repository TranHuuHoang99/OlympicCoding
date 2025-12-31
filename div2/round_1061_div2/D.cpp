/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-26 10:05:28 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int ask(int idx, int val) {
 	cout << '?' << ' ' << idx << ' ' << val << endl;
 	int ret;
 	cin >> ret;
 	return ret;
}
void solve(void) {
	cin >> n;
	set<int> per, ori;
	for (int i = 1; i < n; i++) per.insert(i);
	for (int i = 1; i <= n; i++) ori.insert(i);
	int len = (int)log2(n)+1;
	int ret = 0;
	for (int i = 0; i < len; i++) {
		set<int> idx0, idx1;
		for (int idx : per) {
		 	int q = ask(idx, 1 << i);
		 	if (q) {
		 		idx1.insert(idx);
		 	} else {
		 	 	idx0.insert(idx);
		 	}
		}
		set<int> cnt0, cnt1;
		for (int val : ori) {
		 	if (val & (1 << i)) {
		 	 	cnt1.insert(val);
		 	} else {
		 	 	cnt0.insert(val);
		 	}
		}
		if (idx0.size() == cnt0.size()) {
		 	ret += (1 << i);
		 	per = idx1;
		 	ori = cnt1;
		} else if (idx1.size() == cnt1.size()) {
		 	per = idx0;
		 	ori = cnt0;
		} else {
		 	cout << "Error" << endl;
		}
	}
	cout << '!' << ' ' << ret << endl;
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

