/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 14.04.2025 21:53:51
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 4e5+10;
ll tree[N];
int n, q;

ll get_sum(int idx, int left, int right, int u, int v) {
 	if (right < u || v < left) return 0ll;
 	if (u <= left && right <= v) return tree[idx];
 	int mid = (left+right)/2;
 	ll sum1 = get_sum(idx*2, left, mid, u, v);
 	ll sum2 = get_sum(idx*2+1, mid+1, right, u, v);
 	return sum1 + sum2;
}

void update(int idx, int left, int right, int pos, ll val) {
	if (right < pos || pos < left) return;
	if (left == right) {
	 	tree[idx] = val;
	 	return;
	}
	int mid = (left+right)/2;
	update(idx*2, left, mid, pos, val);
	update(idx*2+1, mid+1, right, pos, val);
	tree[idx] = tree[idx*2] + tree[idx*2+1];
}

void solve(void) {
	cin >> n >> q;
	for (int i = 1; i <= q; i++) {
	 	int a, b;
	 	ll c;
	 	cin >> a >> b >> c;
	 	if (a == 1) {
			update(1, 1, n, b, c);
	 	} else {
	 	 	cout << get_sum(1, 1, n, b, (int)c) << endl;
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
