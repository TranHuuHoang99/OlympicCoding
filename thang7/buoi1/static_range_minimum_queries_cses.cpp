#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
const ll M = N * 4;
int n, q;
int tree[M], A[N];

void build(int idx, int left, int right) {
 	if (left == right) {
 	 	tree[idx] = A[left];
 	 	return;
 	}
 	int mid = (left+right)/2;
 	build(idx*2, left, mid);
 	build(idx*2+1, mid+1, right);
 	tree[idx] = min(tree[idx*2], tree[idx*2+1]);
}

int get_min(int idx, int left, int right, int u, int v) {
 	if (u > right || v < left) return INT32_MAX;
 	if (u <= left && right <= v) return tree[idx];
 	int mid = (left+right)/2;
 	return min(get_min(idx*2, left, mid, u, v), get_min(idx*2+1, mid+1, right, u, v));	
}

void solve(void) {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	build(1, 1, n);
	for (int i = 1; i <= q; i++) {
	 	int a, b;
	 	cin >> a >> b;
	 	cout << get_min(1, 1, n, a, b) << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef HOANGPRODN_DEBUG
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG
	solve();

	return 0;
}

