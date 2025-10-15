/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-09 21:05:09 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e4+10;
int n;
int A[N];

bool cmp(int a, int b) {
 	return a > b;
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(A+1, A+1+n, cmp);
	vector<int> sticks;
	for (int i = 1; i <= n-1; i++) {
	 	int left = A[i];
	 	int right = A[i+1];
	 	if (left == right || left-1 == right) {
	 	 	sticks.push_back(right);
	 	 	i++;
	 	}
	}
	ll ret = 0ll;
	for (int i = 0; i < sticks.size(); i+=2) {
		if (i+1 < sticks.size()) {
		 	ret += 1ll * sticks[i] * sticks[i+1];
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

