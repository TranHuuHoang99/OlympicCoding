#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
int n, q;
ll tree[4*N], lazy[2][4*N];
ll A[N];

// tinh tong cac so tu 1 den x
ll val(int x) {
 	return (1ll * x * (x+1)) / 2;   
}	

void build(int idx, int left, int right) {
 	if (left == right) {
 	 	tree[idx] = A[left];
 	 	return;
 	}
 	int mid = (left+right)/2;
 	build(idx*2, left, mid);
 	build(idx*2+1, mid+1, right);
 	tree[idx] = tree[idx*2] + tree[idx*2+1];
}

void push(int idx, int left, int right) {
 	int mid = (left + right)/2;
 	if (lazy[0][idx]) {
 		tree[idx*2] += val(mid-left+1) * lazy[0][idx];
 		tree[idx*2+1] += (val(right-mid) + 1ll * (mid+1-left) * (right-mid)) * lazy[0][idx];
 		lazy[0][idx*2] += lazy[0][idx];
 		lazy[0][idx*2+1] += lazy[0][idx];
 		lazy[1][idx*2+1] += 1ll * (mid+1-left) * lazy[0][idx];
 		lazy[0][idx] = 0;
 	}
 	if (lazy[1][idx]) {
 	 	tree[idx*2] += 1ll * (mid-left+1) * lazy[1][idx];
 	 	tree[idx*2+1] += 1ll * (right-mid) * lazy[1][idx];
 	 	lazy[1][idx*2] += lazy[1][idx];
 	 	lazy[1][idx*2+1] += lazy[1][idx];
		lazy[1][idx] = 0;
 	}
}

void update(int idx, int left, int right, int u, int v) {
 	if (right < u || left > v) return;
 	if (u <= left && right <= v) {
 	 	tree[idx] += val(right-left+1) + 1ll * (right-left+1) * (left-u);
 	 	lazy[0][idx]++;
 	 	lazy[1][idx] += left-u;
 	 	return;
 	}
 	int mid = (left+right)/2;
 	push(idx, left, right);
 	update(idx*2, left, mid, u, v);
 	update(idx*2+1, mid+1, right, u, v);
 	tree[idx] = tree[idx*2] + tree[idx*2+1];
}

ll get(int idx, int left, int right, int u, int v) {
 	if (right < u || left > v) return 0;
 	if (u <= left && right <= v) return tree[idx];
 	int mid = (left+right)/2;
 	push(idx, left, right);
 	return get(idx*2, left, mid, u, v) + get(idx*2+1, mid+1, right, u, v);
}

void solve(void) {
 	cin >> n;
 	for (int i = 1; i <= n; i++) cin >> A[i];
 	build(1,1,n);
 	cin >> q;
 	for (int i = 1; i <= q; i++) {
 	 	int a, b, c;
 	 	cin >> a >> b >> c;
 	 	if (a == 1) {
 	 	 	update(1, 1, n, b, c);
 	 	} else {
 	 	 	cout << get(1, 1, n, b, c) << endl;
 	 	}
 	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG
	
	solve();

	return 0;
}

