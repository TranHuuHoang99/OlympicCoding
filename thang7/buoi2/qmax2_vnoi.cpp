#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 5e4+10;
ll tree[4*N], lazy[4*N];
int n, m;

void push(int idx) {
 	if (lazy[idx]) {
 	 	tree[idx*2] += lazy[idx];
 	 	tree[idx*2+1] += lazy[idx];
 	 	lazy[idx*2] += lazy[idx];
 	 	lazy[idx*2+1] += lazy[idx];
 	 	lazy[idx] = 0ll;
 	}
}

void update(int idx, int left, int right, int u, int v, ll val) {
 	if (u > right || v < left) return;
 	if (u <= left && right <= v) {
 	 	tree[idx] += val;
 	 	lazy[idx] += val;
 	 	return;
 	}
 	int mid = (left+right)/2;
 	push(idx);
 	update(idx*2, left, mid, u, v, val);
 	update(idx*2+1, mid+1, right, u, v, val);
 	tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

ll get_max(int idx, int left, int right, int u, int v) {
 	if (u > right || v < left) return 0ll;
 	if (u <= left && right <= v) return tree[idx];
 	int mid = (left+right)/2;
 	push(idx);
 	ll left_val = get_max(idx*2, left, mid, u, v);
 	ll right_val = get_max(idx*2+1, mid+1, right, u, v);
 	return max(left_val, right_val);
}

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a;
		if (a == 0) {
		 	ll d;
		 	cin >> b >> c >> d;
		 	update(1, 1, n, b, c, d);
     	} else {
     	 	cin >> b >> c;
     	 	cout << get_max(1, 1, n, b, c) << endl;
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

