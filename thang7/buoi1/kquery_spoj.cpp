#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e5+10;
int n, q;
int A[N];
vector<int> tree[4*N];

vector<int> mergeSort(const vector<int>& a, const vector<int>& b) {
 	vector<int> ret;
 	int idx1 = 0, idx2 = 0;
 	while (idx1 < a.size() && idx2 < b.size()) {
 	 	if (a[idx1] < b[idx2]) {
 	 	 	ret.push_back(a[idx1]);
 	 	 	idx1++;
 	 	} else {
 	 		ret.push_back(b[idx2]);
 	 		idx2++;	
 		}
 	}
 	while (idx1 < a.size()) {
 	 	ret.push_back(a[idx1]);
 	 	idx1++;
 	}
 	while (idx2 < b.size()) {
 	 	ret.push_back(b[idx2]);
 	 	idx2++;
 	}
 	return ret;
}

void build(int idx, int left, int right) {
 	if (left == right) {
 	 	tree[idx].push_back(A[left]);
 	 	return;
 	}
 	int mid = (left+right)/2;
 	build(idx*2, left, mid);
 	build(idx*2+1, mid+1, right);
 	tree[idx] = mergeSort(tree[idx*2], tree[idx*2+1]);
}

int get_numb(int idx, int left, int right, int u, int v, int k) {
 	if (u > right || v < left) return 0;
 	if (u <= left && right <= v) {
 	 	int l = 0;
 	 	int r = tree[idx].size()-1;
 	 	int pos = tree[idx].size();
 	 	while (l <= r) {
 			int m = (l+r)/2;
 			if (tree[idx][m] > k) {
 				pos = m;
 				r = m - 1;				
	 	 	} else {
	 	 	 	l = m + 1;
	 		}
 	 	}
 	 	return tree[idx].size() - pos;
 	}
 	int mid = (left+right)/2;
 	int left_numb = get_numb(idx*2, left, mid, u, v, k);
 	int right_numb = get_numb(idx*2+1, mid+1, right, u, v, k);
 	return left_numb + right_numb;
}

void solve(void) {
 	cin >> n;
 	for (int i = 1; i <= n; i++) cin >> A[i];
	build(1, 1, n);
	cin >> q;
	for (int i = 1; i <= q; i++) {
	 	int a, b, c;
	 	cin >> a >> b >> c;
	 	cout << get_numb(1, 1, n, a, b, c) << endl;
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



























