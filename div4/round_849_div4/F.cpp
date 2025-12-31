/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-12-01 15:58:47 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n, q;
int A[N];
set<int> save;
int cal_sum(int val) {
 	int ret = 0;
 	while (val) {
 	 	ret += val % 10;
 	 	val /= 10;
 	}
 	return ret;
}
void solve(void) {
 	cin >> n >> q;
 	save.clear();
 	for (int i = 1; i <= n; i++) {
 	 	cin >> A[i];
 	 	if (A[i] > 9) save.insert(i);
 	}
 	for (int i = 1; i <= q; i++) {
 	 	int type;
 	 	cin >> type;
 	 	if (type == 1) {
 	 	 	int left, right;
 	 	 	cin >> left >> right;
 	 	 	int last = left;
 	 	 	while (!save.empty()) {
 	 	 	 	auto it = save.lower_bound(last);
 	 	 	 	if (it == save.end() || *it > right) break;
 	 	 	 	A[*it] = cal_sum(A[*it]);
 	 	 	 	auto temp_idx = *it;
 	 	 	 	save.erase(it);
 	 	 	 	if (A[temp_idx] > 9) save.insert(temp_idx);
 	 	 	 	last = temp_idx + 1;
 	 	 	}
 	 	} else {
 	 	 	int pos;
 	 	 	cin >> pos;
 	 	 	cout << A[pos] << endl;
 	 	}
 	}
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
 