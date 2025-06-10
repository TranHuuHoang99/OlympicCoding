#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
const ll M = 6e5+10;
int n;
ll H[N], A[N];
ll tree[M];
ll dp[N];

void update(int idx, int left, int right, int height, ll val) {
 	if (height < left || height > right) return;
 	if (left == right && left == height) {
 	 	tree[idx] = val;
 	 	return;
 	}
 	int mid = (left+right)/2;
 	update(idx*2, left, mid, height, val);
 	update(idx*2+1, mid+1, right, height, val);
 	tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

ll get_max(int idx, int left, int right, int u, int v) {
 	if (u > right || v < left) return 0ll;
 	if (u <= left && right <= v) return tree[idx];
 	int mid = (left+right)/2;
 	return max(get_max(idx*2, left, mid, u, v), get_max(idx*2+1, mid+1, right, u, v));
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> H[i];
	for (int i = 1; i <= n; i++) cin >> A[i];	
	for (int i = 1; i <= n; i++) {
	 	ll max_val = get_max(1, 1, n, 1, H[i]-1);
	 	dp[i] = max_val + A[i];
	 	update(1, 1, n, H[i], dp[i]);
	}
	ll ret = LLONG_MIN;
	for (int i = 1; i <= n; i++) ret = max(ret, dp[i]);
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

