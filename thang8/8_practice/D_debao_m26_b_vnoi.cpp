/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-05 20:57:43 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
int n;
int A[N];
set<int> cur;
set<int> ans;

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) {
	 	cur.insert(0);
	 	set<int> temp;
	 	for (int c : cur) {
	 	 	temp.insert(A[i] | c);
	 	 	ans.insert(A[i] | c);
	 	}
	 	cur = temp;
	}
	cout << ans.size() << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

