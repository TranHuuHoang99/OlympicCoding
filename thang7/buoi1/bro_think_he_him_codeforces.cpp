#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
const ll MOD = 998244353LL;
struct Element {
  	ll numb; // number of subsequence that have head and tail same as it's parents
  	ll numbDiff; // number of subsequence that have head and tail different to each other
};
struct Node {
 	Element info[2][2];
 	Node (void) {
 		for (int head = 0; head <= 1; head++) {
 		 	for (int tail = 0; tail <= 1; tail++) {
 		 	 	info[head][tail].numb = 0ll;
 		 	 	info[head][tail].numbDiff = 0ll;
 		 	}
 		}
 	}
};
Node mergeNode(const Node& a, const Node& b) {
 	Node new_node;
 	for (int head1 = 0; head1 <= 1; head1++) {
 	 	for (int tail1 = 0; tail1 <= 1; tail1++) {
 	 	 	for (int head2 = 0; head2 <= 1; head2++) {
 	 	 	 	for (int tail2 = 0; tail2 <= 1; tail2++) {
 	 	 	 	 	new_node.info[head1][tail2].numb += a.info[head1][tail1].numb * b.info[head2][tail2].numb;
 	 	 	 	 	new_node.info[head1][tail2].numbDiff += a.info[head1][tail1].numbDiff * b.info[head2][tail2].numb;
 	 	 	 	 	new_node.info[head1][tail2].numbDiff += a.info[head1][tail1].numb * b.info[head2][tail2].numbDiff;
 	 	 	 	 	if (tail1 != head2) {
 	 	 	 	 	 	new_node.info[head1][tail2].numbDiff += a.info[head1][tail1].numb * b.info[head2][tail2].numb;
 	 	 	 	 	}
 	 	 	 	}
 	 	 	}
 	 	}
 	}
 	for (int head = 0; head <= 1; head++) {
 	 	for (int tail = 0; tail <= 1; tail++) {
 	 	 	new_node.info[head][tail].numb += (a.info[head][tail].numb + b.info[head][tail].numb);
 	 	 	new_node.info[head][tail].numbDiff += (a.info[head][tail].numbDiff + b.info[head][tail].numbDiff);
 	 	 	new_node.info[head][tail].numb %= MOD;
 	 	 	new_node.info[head][tail].numbDiff %= MOD;
 	 	}
 	}
 	return new_node;
}
Node tree[4*N];
string str;
int q;

void build(int idx, int left, int right) {
	if (left == right) {
	 	for (int head = 0; head <= 1; head++) {
	 	 	for (int tail = 0; tail <= 1; tail++) {
	 	 	 	tree[idx].info[head][tail].numb = 0ll;
	 	 	 	tree[idx].info[head][tail].numbDiff = 0ll;
	 	 	}
	 	}
	 	if (str[left] == '1') {
	 	 	tree[idx].info[1][1].numb = 1ll;
	 	} else {
	 	 	tree[idx].info[0][0].numb = 1ll;
	 	}
	 	return;
	}
	int mid = (left+right)/2;
	build(idx*2, left, mid);
	build(idx*2+1, mid+1, right);
	tree[idx] = mergeNode(tree[idx*2], tree[idx*2+1]);
}

void update(int idx, int left, int right, int pos) {
 	if (left > pos || right < pos) return;
 	if (left == right) {
 		for (int head = 0; head <= 1; head++) {
 		 	for (int tail = 0; tail <= 1; tail++) {
 		 	 	tree[idx].info[head][tail].numb = 0ll;
 		 	 	tree[idx].info[head][tail].numbDiff = 0ll;
 		 	}
 		}
		if (str[pos] == '1') {
		 	tree[idx].info[1][1].numb = 1ll;
 		} else {
 		 	tree[idx].info[0][0].numb = 1ll;
 		}
 		return;
 	}
 	int mid = (left+right)/2;
 	update(idx*2, left, mid, pos);
 	update(idx*2+1, mid+1, right, pos);
 	tree[idx] = mergeNode(tree[idx*2], tree[idx*2+1]);
}

void solve(void) {
	str.clear();
	cin >> str;
	int n = str.size();
	str = " " + str;
	build(1, 1, n);
	ll val = 1ll;
	for (int i = 1; i <= n; i++) {
	 	val = (val % MOD * 2ll % MOD) % MOD;
	}
	val -= 1ll;
	cin >> q;
	for (int i = 1; i <= q; i++) {
	 	int pos;
	 	cin >> pos;
	 	if (str[pos] == '1') {
	 	 	str[pos] = '0';
	 	} else {
	 	 	str[pos] = '1';
	 	}
	 	update(1, 1, n, pos);
	 	ll ret = val;
	 	for (int head = 0; head <= 1; head++) {
	 		for (int tail = 0; tail <= 1; tail++) {
	 		 	(ret += tree[1].info[head][tail].numbDiff) %= MOD;
	 		}
	 	}
	 	cout << ret << ' ';
	}
	cout << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}

