/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 23.04.2025 20:42:46
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e9+7;

struct Node {
  	int prefix, suffix, sum, maxSum;
  	static Node inf(void) {
  	 	return {
			-INF, -INF, 0, -INF  	 	  	
  	 	};
  	}
  	static Node merge(const Node& left_node, const Node& right_node) {
  	 	Node ret;
  	 	ret.prefix = max(left_node.prefix, left_node.sum + right_node.prefix);
  	 	ret.suffix = max(right_node.suffix, right_node.sum + left_node.suffix);
  	 	ret.sum = left_node.sum + right_node.sum;
  	 	ret.maxSum = max(left_node.maxSum, right_node.maxSum);
  	 	ret.maxSum = max(ret.maxSum, left_node.suffix + right_node.prefix);
  	 	return ret;
  	}
};

const ll N = 5e5+10;
int n, m, A[N];
Node tree[4*N+10];

void build(int idx, int left, int right) {
 	if (left == right) {
 	 	tree[idx] = {A[left], A[left], A[left], A[left]};
 	 	return;
 	}
 	int mid = (left+right)/2;
 	build(idx*2, left, mid);
 	build(idx*2+1, mid+1, right);
 	tree[idx] = Node::merge(tree[idx*2], tree[idx*2+1]);
}

Node get(int idx, int left, int right, int u, int v) {
 	if (right < u || left > v) return Node::inf();
 	if (u <= left && right <= v) return tree[idx];
 	int mid = (left+right)/2;
 	Node temp1 = get(idx*2, left, mid, u, v);
 	Node temp2 = get(idx*2+1, mid+1, right, u, v);
 	return Node::merge(temp1, temp2);
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	build(1, 1, n);
	cin >> m;
	for (int i = 1; i <= m; i++) {
	 	int a, b;
	 	cin >> a >> b;
	 	cout << get(1, 1, n, a, b).maxSum << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
