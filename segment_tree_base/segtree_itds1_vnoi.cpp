/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 23.04.2025 21:04:31
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int n, m, A[N];
multiset<int> tree[4*N];

void build(int idx, int left, int right) {
 	if (left == right) {
 	    tree[idx].insert(A[left]);
 	    return;
	}
	int mid = (left+right)/2;
	build(idx*2, left, mid);
	build(idx*2+1, mid+1, right);
	tree[idx] = tree[idx*2+1];
	for (int e : tree[idx*2]) tree[idx].insert(e);	
}

void update(int idx, int left, int right, int i, int old_val, int new_val) {
 	if (right < i || left > i) return;
 	if (left == right) {
 	 	tree[idx].clear();
 	 	tree[idx].insert(new_val);
 	 	return;
 	}
 	int mid = (left+right)/2;
 	update(idx*2, left, mid, i, old_val, new_val);
 	update(idx*2+1, mid+1, right, i, old_val, new_val);
 	tree[idx].erase(tree[idx].find(old_val));
 	tree[idx].insert(new_val);
}

int get(int idx, int left, int right, int u, int v, int k) {
 	if (right < u || left > v) return INT32_MAX;
 	if (u <= left && right <= v) {
 	 	auto it = tree[idx].lower_bound(k);
 	 	if (it == tree[idx].end()) return INT32_MAX;
 	 	return *it;
 	}
 	int mid = (left+right)/2;
 	int temp1 = get(idx*2, left, mid, u, v, k);
 	int temp2 = get(idx*2+1, mid+1, right, u, v, k);
 	return min(temp1, temp2);
}

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> A[i];
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
	 	int type;
	 	cin >> type;
	 	if (type == 1) {
	 	 	int a, b;
	 	 	cin >> a >> b;
			update(1, 1, n, a, A[a], b);
			A[a] = b;
	 	} else {
	 	 	int a, b, c;
	 	 	cin >> a >> b >> c;
	 	 	int ret = get(1, 1, n, a, b, c);
	 	 	if (ret == INT32_MAX) ret = -1;
	 	 	cout << ret << endl;
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
