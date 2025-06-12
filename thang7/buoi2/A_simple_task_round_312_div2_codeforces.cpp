#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int n, q;
string str;
int tree[4*N][26], lazy[4*N][26];
int cnt[26];

void build(int idx, int left, int right) {
 	for (int i = 0; i < 26; i++) lazy[idx][i] = -1;
 	if (left == right) {
 	 	tree[idx][str[left]-'a'] = 1;
 	 	return;
 	}
 	int mid = (left+right)/2;
 	build(idx*2, left, mid);
 	build(idx*2+1, mid+1, right);
 	for (int i = 0; i < 26; i++) {
 	 	tree[idx][i] = tree[idx*2][i] + tree[idx*2+1][i];
 	}
}

void push(int idx, int left, int right, int ch) {
    if (lazy[idx][ch] == -1) return;
    int mid = (left+right)/2;
    tree[idx*2][ch] = (mid-left+1) * lazy[idx][ch];
    tree[idx*2+1][ch] = (right-mid) * lazy[idx][ch];
    lazy[idx*2][ch] = lazy[idx][ch];
    lazy[idx*2+1][ch] = lazy[idx][ch];
    lazy[idx][ch] = -1;
}	

void update(int idx, int left, int right, int u, int v, int val, int ch) {
 	if (u > right || v < left) return;
 	if (u <= left && right <= v) {
 	 	tree[idx][ch] = (right-left+1) * val;
 	 	lazy[idx][ch] = val;
 	 	return;
 	}
 	int mid = (left+right)/2;
 	push(idx, left, right, ch);
	update(idx*2, left, mid, u, v, val, ch);
	update(idx*2+1, mid+1, right, u, v, val, ch);
	tree[idx][ch] = tree[idx*2][ch] + tree[idx*2+1][ch];
}

int get(int idx, int left, int right, int u, int v, int ch) {
 	if (u > right || v < left) return 0;
 	if (u <= left && right <= v) return tree[idx][ch];
 	int mid = (left+right)/2;
 	push(idx, left, right, ch);
 	int left_val = get(idx*2, left, mid, u, v, ch);
 	int right_val = get(idx*2+1, mid+1, right, u, v, ch);
 	return left_val + right_val;
}

void solve(void) {
 	cin >> n >> q;
 	cin >> str;
 	str = " " + str;
 	build(1, 1, n);
 	for (int i = 1; i <= q; i++) {
 	 	int a, b, c;
 	 	cin >> a >> b >> c;
		for (int ch = 0; ch < 26; ch++) {
		 	cnt[ch] = get(1, 1, n, a, b, ch);
		 	update(1, 1, n, a, b, 0, ch);
		}
		int k = (c == 0) ? -1 : 1;
		int ch = (c == 0) ? 25 : 0;
		int u = a;
		while (0 <= ch && ch <= 25) {
		 	if (cnt[ch] > 0) {
		 	 	update(1, 1, n, u, u + cnt[ch] - 1, 1, ch);
		 	 	u += cnt[ch];
		 	}
		 	ch += k;
		}
 	}
	string ret = "";
	for (int i = 1; i <= n; i++) {
	 	for (int ch = 0; ch < 26; ch++) {
	 	 	if (get(1, 1, n, i , i, ch) > 0) {
	 	 	 	ret += char(ch+'a');
	 	 	}
	 	}
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}





































