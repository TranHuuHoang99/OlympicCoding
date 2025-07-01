#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 6e4+10;
int n;
int A[N];
int it[4*N];

void update(int idx, int left, int right, int pos) {
	if (pos > right || pos < left) return;
 	if (left == right && left == pos) {
 	 	it[idx] += 1;
 	 	return;
 	}
 	int mid = (left+right)/2;
 	update(idx*2, left, mid, pos);
 	update(idx*2+1, mid+1, right, pos);
 	it[idx] = it[idx*2] + it[idx*2+1];
}

int get_val(int idx, int left, int right, int u, int v) {
 	if (u > right || v < left) return 0;
 	if (u <= left && right <= v) return it[idx];
 	int mid = (left+right)/2;
 	int left_val = get_val(idx*2, left, mid, u, v);
 	int right_val = get_val(idx*2+1, mid+1, right, u, v);
 	return left_val + right_val;
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	int ret = 0;
	for (int i = n; i >= 1; i--) {
	 	ret += get_val(1, 1, 6e4, 1, A[i]-1);
	 	update(1, 1, 6e4, A[i]);
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

