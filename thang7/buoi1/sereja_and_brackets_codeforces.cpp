#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
 	int completeBrackets;
 	int freeOpen;
 	int freeClose;
};
const ll N = 1e6+10;
const ll M = 4e6+10;
string str;
int n, m;
Node tree[M];

void build(int idx, int left, int right) {
 	if (left == right) {
 	 	if (str[left] == '(') {
 	 		tree[idx] = (Node){0,1,0};	 	
		} else {
		 	tree[idx] = (Node){0,0,1};
		}
		return;
 	}
 	int mid = (left+right)/2;
 	build(idx*2, left, mid);
 	build(idx*2+1, mid+1, right);
 	int addition = min(tree[idx*2].freeOpen, tree[idx*2+1].freeClose);
 	tree[idx].completeBrackets = tree[idx*2].completeBrackets + tree[idx*2+1].completeBrackets + 2 * addition;
 	tree[idx].freeOpen = tree[idx*2].freeOpen + tree[idx*2+1].freeOpen - addition;
 	tree[idx].freeClose = tree[idx*2].freeClose + tree[idx*2+1].freeClose - addition; 
}

Node get_node(int idx, int left, int right, int u, int v) {
 	if (u > right || v < left) return (Node){0,0,0};
 	if (u <= left && right <= v) return tree[idx];
 	int mid = (left+right)/2;
	Node leftNode = get_node(idx*2, left, mid, u, v);
	Node rightNode = get_node(idx*2+1, mid+1, right, u, v);
	Node ret;
	int addition = min(leftNode.freeOpen, rightNode.freeClose);
	ret.completeBrackets = leftNode.completeBrackets + rightNode.completeBrackets + 2 * addition;
	ret.freeOpen = leftNode.freeOpen + rightNode.freeOpen - addition;
	ret.freeClose = leftNode.freeClose + rightNode.freeClose - addition;
	return ret;
}

void solve(void) {
 	cin >> str;
 	int n = str.size();
 	str = " " + str;
 	build(1, 1, n);
 	cin >> m;
 	for (int i = 1; i <= m; i++) {
 	 	int a, b;
 	 	cin >> a >> b;
 	 	Node temp = get_node(1, 1, n, a, b);
 	 	cout << temp.completeBrackets << endl;
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

