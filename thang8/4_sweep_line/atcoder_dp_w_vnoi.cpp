/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-07-31 22:33:50 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n, m;
ll A[N];
vector<pair<int,ll>> save[N];
ll it[4*N], lazy[4*N];

void lazyUpdate(int idx) {
 	if (lazy[idx] != 0ll) {
 	 	it[idx*2] += lazy[idx];
 	 	it[idx*2+1] += lazy[idx];
 	 	lazy[idx*2] += lazy[idx];
 	 	lazy[idx*2+1] += lazy[idx];
 	 	lazy[idx] = 0ll;
 	}
}

void update(int idx, int left, int right, int u, int v, ll val) {
 	if (u > right || v < left) return;
 	if (u <= left && right <= v) {
 	 	it[idx] += val;
 	 	lazy[idx] += val;
 	 	return;
 	}
	int mid = (left+right)>>1;
	lazyUpdate(idx);
	update(idx*2, left, mid, u, v, val);
	update(idx*2+1, mid+1, right, u, v, val);
	it[idx] = max(it[idx*2], it[idx*2+1]);
}

ll get_val(int idx, int left, int right, int u, int v) {
 	if (u > right || v < left) return LLONG_MIN;
 	if (u <= left && right <= v) return it[idx];
 	int mid = (left+right)>>1;
 	lazyUpdate(idx);
 	ll left_val = get_val(idx*2, left, mid, u, v);
 	ll right_val = get_val(idx*2+1, mid+1, right, u, v);
 	return max(left_val, right_val);
}

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
	 	int left, right;
	 	ll val;
	 	cin >> left >> right >> val;
	 	A[left] += val;
	 	save[right+1].push_back({left,val});
	}
	ll ret = 0ll;
	for (int i = 1; i <= n; i++) {
	 	update(1, 0, n, 0, i-1, A[i]);
	 	for (int j = 0; j < save[i].size(); j++) {
	 	 	pair<int,ll> temp = save[i][j];
	 	 	update(1, 0, n, 0, temp.first-1, -temp.second);
	 	}
	 	ll max_val = get_val(1, 0, n, 0, i-1);
	 	ret = max(ret, max_val);
	 	update(1, 0, n, i, i, max_val);
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

