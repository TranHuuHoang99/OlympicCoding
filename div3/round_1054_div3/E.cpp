/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-11-18 22:02:40 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
map<int,int> savex, savey;
int n, k, l, r;
int A[N];
void solve(void) {
	cin >> n >> k >> l >> r;
	savex.clear();
	savey.clear();
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
	 	savex[A[i]] = 0;
	 	savey[A[i]] = 0;
	}
	ll ret = 0ll;
	int x = 0;
	int y = 1;
	int cntx = 0; // number of distinct element which is equal to k
	int cnty = 0; // number of distinct element which is at most k
	for (int i = 1; i <= n; i++) {
	 	while (y <= n && cnty <= k) {
	 	 	if (savey[A[y]] == 0) {
	 	 	 	if (cnty == k) break;
	 	 	 	cnty++;
	 	 	}
	 	 	savey[A[y]]++;
	 	 	y++;
	 	}
	 	while (x+1 <= n && cntx < k) {
	 	 	if (savex[A[x+1]] == 0) {
	 	 	 	cntx++;
	 	 	}
	 	 	savex[A[x+1]]++;
	 	 	x++;
	 	}
	 	if (cntx == k) {
	 	 	ret += 1ll * max(0, min(y-1, i+r-1) - max(x, i+l-1) + 1);
	 	}
	 	savex[A[i]]--;
	 	savey[A[i]]--;
	 	if (savex[A[i]] == 0) cntx--;
	 	if (savey[A[i]] == 0) cnty--;
	}
	cout << ret << endl;
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

