/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-09-29 19:49:03 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n, q;
ll it[4*N];
ll lazy[4*N][2]; // index 0 for the number of triangle, index 1 for the height of rectangle
ll A[N];
ll val(int x) {
 	return (1ll * x * (x+1) / 2); // cong thu cap so cong, (so dau + so cuoi) * so so hang / 2
}
void build(int idx, int left, int right) {
 	if (left == right) {
 	 	it[idx] = A[left];
 	 	return;
 	}
 	int mid = (left+right)>>1;
 	build(idx*2, left, mid);
 	build(idx*2+1, mid+1, right);
 	it[idx] = it[idx*2] + it[idx*2+1];
}
void lazy_update(int idx, int left, int right) {
 	int mid = (left+right)>>1;
 	if (lazy[idx][0] > 0) {
 	 	it[idx*2] += val(mid-left+1) * lazy[idx][0];
 	 	it[idx*2+1] += val(right-mid) * lazy[idx][0] + 1ll * ((mid+1)-left) * (right-(mid+1)+1) * lazy[idx][0];
		lazy[idx*2][0] += lazy[idx][0];
		lazy[idx*2+1][0] += lazy[idx][0];
		lazy[idx*2+1][1] += ((mid+1)-left) * lazy[idx][0];
		lazy[idx][0] = 0ll;
 	}
	if (lazy[idx][1] > 0) {
	 	it[idx*2] += lazy[idx][1] * 1ll * (mid-left+1);
	 	it[idx*2+1] += lazy[idx][1] * 1ll * (right-(mid+1)+1);
	 	lazy[idx*2][1] += lazy[idx][1];
	 	lazy[idx*2+1][1] += lazy[idx][1];
	 	lazy[idx][1] = 0ll; 
	}
}
void update(int idx, int left, int right, int u, int v) {
 	if (u > right || v < left) return;
 	if (u <= left && right <= v) {
 	 	it[idx] += val(right-left+1) + 1ll * (left - u) * (right - left + 1);
 	 	lazy[idx][0]++;
 	 	lazy[idx][1] += 1ll * (left - u);
 	 	return;
 	}
	int mid = (left+right)>>1;
	lazy_update(idx, left, right);
	update(idx*2, left, mid, u, v);
	update(idx*2+1, mid+1, right, u, v);
	it[idx] = it[idx*2] + it[idx*2+1];
}
ll get_val(int idx, int left, int right, int u, int v) {
 	if (u > right || v < left) return 0ll;
 	if (u <= left && right <= v) return it[idx];
 	int mid = (left+right)>>1;
 	lazy_update(idx, left, right);
 	ll left_val = get_val(idx*2, left, mid, u, v);
 	ll right_val = get_val(idx*2+1, mid+1, right, u, v);
 	return left_val + right_val;
}
void solve(void) {
 	cin >> n >> q;
 	for (int i = 1; i <= n; i++) cin >> A[i];
 	build(1, 1, n);
 	for (int i = 1; i <= q; i++) {
		int type, u, v;
		cin >> type >> u >> v;
		if (type == 1) {
		 	update(1, 1, n, u, v);
		} else {
		 	cout << get_val(1, 1, n, u, v) << endl;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

