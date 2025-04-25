/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 23.04.2025 21:26:42
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int n, m;
ll A[N];
ll tree[4*N], lazy[4*N];

void build(int idx, int left, int right) {
	if (left == right) {
	 	tree[idx] = A[left];
	 	return;
	}
	int mid = (left+right)/2;
	build(idx*2, left, mid);
	build(idx*2+1, mid+1, right);
	tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

void push(int idx) {
 	if (lazy[idx]) {
 	 	tree[idx*2] += lazy[idx];
 	 	tree[idx*2+1] += lazy[idx];
 	 	lazy[idx*2] += lazy[idx];
 	 	lazy[idx*2+1] += lazy[idx];
 	 	lazy[idx] = 0;
 	}
}

void update(int idx, int left, int right, int u, int v, ll val) {
 	if (right < u || left > v) return;
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

ll get(int idx, int left, int right, int u, int v) {
 	if (right < u || left > v) return LLONG_MIN;
 	if (u <= left && right <= v) return tree[idx];
 	int mid = (left+right)/2;
 	push(idx);
 	ll temp1 = get(idx*2, left, mid, u, v);
 	ll temp2 = get(idx*2+1, mid+1, right, u, v);
 	return max(temp1, temp2);
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	build(1, 1, n);
	cin >> m;
	for (int i = 1; i <= m; i++) {
	 	int type;
	 	cin >> type;
	 	if (type == 1) {
	 	 	int a, b;
	 	 	ll c;
	 	 	cin >> a >> b >> c;
	 	 	update(1, 1, n, a, b, c);
	 	} else {
	 	 	int a, b;
	 	 	cin >> a >> b;
	 	 	cout << get(1, 1, n, a, b) << endl;
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
