/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-07-21 20:43:46 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
  	ll prefix, suffix;
};
const ll N = 2e5+10;
const ll prime = 31ll;
int n, m;
string pattern;
ll power31[N];
Node it[4*N];

void build(int idx, int left, int right) {
 	if (left == right) {
 	 	int val = int(pattern[left]-'a'+1);
 	 	it[idx].prefix = val * power31[left-1];
 	 	it[idx].suffix = val * power31[n-left];
 	 	return;
 	}
 	int mid = (left+right) / 2;
 	build(idx*2, left, mid);
 	build(idx*2+1, mid+1, right);
 	it[idx].prefix = it[idx*2].prefix + it[idx*2+1].prefix;
 	it[idx].suffix = it[idx*2].suffix + it[idx*2+1].suffix;
}	

void update(int idx, int left, int right, int pos, ll val) {
    if (pos > right || pos < left) return;
    if (left == right && left == pos) {
       	int temp = int(pattern[pos]-'a'+1);
       	it[idx].prefix += val * temp * power31[left-1];
       	it[idx].suffix += val * temp * power31[n-left];
       	return;
    }	
	int mid = (left+right)/2;
	update(idx*2, left, mid, pos, val);
	update(idx*2+1, mid+1, right, pos, val);
	it[idx].prefix = it[idx*2].prefix + it[idx*2+1].prefix;
	it[idx].suffix = it[idx*2].suffix + it[idx*2+1].suffix;
}	

pair<ll,ll> get_pair(int idx, int left, int right, int u, int v) {
    if (u > right || v < left) return {0ll,0ll};
    if (u <= left && right <= v) {
     	return {it[idx].prefix, it[idx].suffix};
    }
    int mid = (left+right)/2;
    pair<ll,ll> left_pair = get_pair(idx*2, left, mid, u, v);
    pair<ll,ll> right_pair = get_pair(idx*2+1, mid+1, right, u, v);
    return {left_pair.first + right_pair.first, left_pair.second + right_pair.second};
}	

void solve(void) {
	cin >> n >> m;
	power31[0] = 1ll;
	for (int i = 1; i <= n; i++) {
	 	power31[i] = power31[i-1] * prime;
	}
	cin >> pattern;
	pattern = " " + pattern;
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
	    int type;
	    cin >> type;
	    if (type == 1) {
	     	int pos;
	     	char x;
	     	cin >> pos >> x;
	     	update(1, 1, n, pos, -1ll);
	     	pattern[pos] = x;
	     	update(1, 1, n, pos, 1ll);
	    } else {
	     	int u, v;
	     	cin >> u >> v;
	     	auto [prefix_val, suffix_val] = get_pair(1, 1, n, u, v);
	     	if (prefix_val * power31[n-v] == suffix_val * power31[u-1]) {
	     	 	cout << "YES" << endl;
	     	} else {
	     	 	cout << "NO" << endl;
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

