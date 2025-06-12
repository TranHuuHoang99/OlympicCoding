#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
const ll MOD = 1e9+7;
struct Node { 
 	ll val0, val1, val2, val3;
 	ll lazy0, lazy1, lazy2, lazy3;
 	Node(void) {
 	    val0 = val1 = val2 = val3 = 0ll;
 	    lazy0 = lazy1 = lazy2 = lazy3 = 0ll;
	}	
};
Node it[4*N];
ll prefix0[N], prefix1[N], prefix2[N], prefix3[N];
int n, m;

void lazyUpdate(int idx, int left, int right) {
	int mid = (left+right)/2;
	it[idx*2].val0 = (it[idx*2].val0 % MOD + (((prefix0[mid] - prefix0[left-1] + MOD) % MOD * it[idx].lazy0 % MOD) % MOD) % MOD) % MOD;
	it[idx*2].lazy0 = (it[idx*2].lazy0 % MOD + it[idx].lazy0 % MOD) % MOD;
	it[idx*2].val1 = (it[idx*2].val1 % MOD + (((prefix1[mid] - prefix1[left-1] + MOD) % MOD * it[idx].lazy1 % MOD) % MOD) % MOD) % MOD;
	it[idx*2].lazy1 = (it[idx*2].lazy1 % MOD + it[idx].lazy1 % MOD) % MOD;
	it[idx*2].val2 = (it[idx*2].val2 % MOD + (((prefix2[mid] - prefix2[left-1] + MOD) % MOD * it[idx].lazy2 % MOD) % MOD) % MOD) % MOD;
	it[idx*2].lazy2 = (it[idx*2].lazy2 % MOD + it[idx].lazy2 % MOD) % MOD;
	it[idx*2].val3 = (it[idx*2].val3 % MOD + (((prefix3[mid] - prefix3[left-1] + MOD) % MOD * it[idx].lazy3 % MOD) % MOD) % MOD) % MOD;
	it[idx*2].lazy3 = (it[idx*2].lazy3 % MOD + it[idx].lazy3 % MOD) % MOD;

	it[idx*2+1].val0 = (it[idx*2+1].val0 % MOD + (((prefix0[right] - prefix0[mid] + MOD) % MOD * it[idx].lazy0 % MOD) % MOD) % MOD) % MOD;
	it[idx*2+1].lazy0 = (it[idx*2+1].lazy0 % MOD + it[idx].lazy0 % MOD) % MOD;
	it[idx*2+1].val1 = (it[idx*2+1].val1 % MOD + (((prefix1[right] - prefix1[mid] + MOD) % MOD * it[idx].lazy1 % MOD) % MOD) % MOD) % MOD;
	it[idx*2+1].lazy1 = (it[idx*2+1].lazy1 % MOD + it[idx].lazy1 % MOD) % MOD;
	it[idx*2+1].val2 = (it[idx*2+1].val2 % MOD + (((prefix2[right] - prefix2[mid] + MOD) % MOD * it[idx].lazy2 % MOD) % MOD) % MOD) % MOD;
	it[idx*2+1].lazy2 = (it[idx*2+1].lazy2 % MOD + it[idx].lazy2 % MOD) % MOD;
	it[idx*2+1].val3 = (it[idx*2+1].val3 % MOD + (((prefix3[right] - prefix3[mid] + MOD) % MOD * it[idx].lazy3 % MOD) % MOD) % MOD) % MOD;
	it[idx*2+1].lazy3 = (it[idx*2+1].lazy3 % MOD + it[idx].lazy3 % MOD) % MOD;

	it[idx].lazy0 = it[idx].lazy1 = it[idx].lazy2 = it[idx].lazy3 = 0ll;
}

void update(int idx, int left, int right, int u, int v, ll v0, ll v1, ll v2, ll v3) {
 	if (u > right || v < left) return;
 	if (u <= left && right <= v) {
		it[idx].val0 = (it[idx].val0 % MOD + ((prefix0[right] - prefix0[left-1] + MOD) % MOD * v0 % MOD) % MOD) % MOD;
		it[idx].val1 = (it[idx].val1 % MOD + ((prefix1[right] - prefix1[left-1] + MOD) % MOD * v1 % MOD) % MOD) % MOD;
		it[idx].val2 = (it[idx].val2 % MOD + ((prefix2[right] - prefix2[left-1] + MOD) % MOD * v2 % MOD) % MOD) % MOD;
		it[idx].val3 = (it[idx].val3 % MOD + ((prefix3[right] - prefix3[left-1] + MOD) % MOD * v3 % MOD) % MOD) % MOD;
		it[idx].lazy0 = (it[idx].lazy0 % MOD + v0 % MOD) % MOD;
		it[idx].lazy1 = (it[idx].lazy1 % MOD + v1 % MOD) % MOD;
		it[idx].lazy2 = (it[idx].lazy2 % MOD + v2 % MOD) % MOD;
		it[idx].lazy3 = (it[idx].lazy3 % MOD + v3 % MOD) % MOD;
		return;
 	}
 	int mid = (left+right)/2;
 	lazyUpdate(idx, left, right);
 	update(idx*2, left, mid, u, v, v0, v1, v2, v3);
 	update(idx*2+1, mid+1, right, u, v, v0, v1, v2, v3);
 	it[idx].val0 = (it[idx*2].val0 % MOD + it[idx*2+1].val0 % MOD) % MOD;
 	it[idx].val1 = (it[idx*2].val1 % MOD + it[idx*2+1].val1 % MOD) % MOD;
 	it[idx].val2 = (it[idx*2].val2 % MOD + it[idx*2+1].val2 % MOD) % MOD;
 	it[idx].val3 = (it[idx*2].val3 % MOD + it[idx*2+1].val3 % MOD) % MOD;
}

ll get_sum(int idx, int left, int right, int u, int v) {
 	if (u > right || v < left) return 0ll;
 	if (u <= left && right <= v) {
 	 	ll ret = 0ll;
 	 	ret = (ret % MOD + it[idx].val0 % MOD) % MOD;
 	 	ret = (ret % MOD + it[idx].val1 % MOD) % MOD;
 	 	ret = (ret % MOD + it[idx].val2 % MOD) % MOD;
 	 	ret = (ret % MOD + it[idx].val3 % MOD) % MOD;
 	 	return ret;
 	}
 	int mid = (left+right)/2;
 	lazyUpdate(idx, left, right);
 	ll left_val = get_sum(idx*2, left, mid, u, v);
 	ll right_val = get_sum(idx*2+1, mid+1, right, u, v);
 	return (left_val % MOD + right_val % MOD) % MOD;
}

void solve(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
	 	prefix0[i] = (prefix0[i] % MOD + prefix0[i-1] % MOD + 1ll % MOD) % MOD;
	 	prefix1[i] = (prefix1[i] % MOD + prefix1[i-1] % MOD + 1ll * i % MOD) % MOD;
	 	prefix2[i] = (prefix2[i] % MOD + prefix2[i-1] % MOD + 1ll * i * i % MOD) % MOD;
	 	prefix3[i] = (prefix3[i] % MOD + prefix3[i-1] % MOD + 1ll * i * i * i % MOD) % MOD;
	}
	for (int i = 1; i <= m; i++) {
	    int type;
	    cin >> type;
	    if (type == 0) {
	     	int left, right;
	     	cin >> left >> right;
	     	cout << get_sum(1, 1, n, left, right) << endl;
	    } else {
	     	int l, r;
	     	cin >> l >> r;
	     	ll v0 = (-(1LL * l * l * l) % MOD + MOD) % MOD;
	     	(v0 += (6LL * l * l) % MOD + 6LL) %= MOD;
	     	v0 -= (11LL * l) % MOD;
	     	(v0 += MOD) %= MOD;
	     	ll v1 = (3LL * l * l + 11LL) % MOD;
	     	v1 -= (12LL * l) % MOD;
	     	(v1 += MOD) %= MOD;
	     	ll v2 = (-3LL * l + 6LL) % MOD;
	     	(v2 += MOD) %= MOD; 
	     	ll v3 = 1LL;
	     	if (type == 1) {
	     		update(1, 1, n, l, r, v0, v1, v2, v3);
	       	} else {
	       	 	update(1, 1, n, l, r, MOD-v0, MOD-v1, MOD-v2, MOD-v3);
	       	}
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
























