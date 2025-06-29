#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
  	ll val;
  	Node* left;
  	Node* right;
};
const ll N = 2e5+10;
int n, q;
ll A[N];
vector<Node*> version;

Node* createNode(void) {
 	Node* ret = new Node();
 	ret->left = nullptr;
 	ret->right = nullptr;
 	ret->val = 0ll;
 	return ret;
}

void build(Node* &root, int left, int right) {
 	root = createNode();
 	if (left == right) {
 	 	root->val = A[left];
 	 	return;
 	}
 	int mid = (left+right)/2;
 	build(root->left, left, mid);
 	build(root->right, mid+1, right);
 	root->val = root->left->val + root->right->val;
}

void update(Node* &root, int left, int right, int pos, ll val) {
	if (left == right) {
	 	root = createNode();
	 	root->val = val;
	 	return;
	}
	Node* temp = createNode();
	*temp = *root;
	int mid = (left+right)/2;
	if (pos <= mid) {
	 	update(temp->left, left, mid, pos, val);
	} else {
	 	update(temp->right, mid+1, right, pos, val);
	}
	root = temp;
	root->val = root->left->val + root->right->val;
}

ll get_sum(Node* root, int left, int right, int u, int v) {
 	if (u > right || v < left) return 0ll;
 	if (u <= left && right <= v) {
 	 	return root->val;
 	}
 	int mid = (left+right)/2;
	ll left_val = get_sum(root->left, left, mid, u, v);
	ll right_val = get_sum(root->right, mid+1, right, u, v);
	return left_val + right_val;
}

void solve(void) {
 	cin >> n >> q;
 	for (int i = 1; i <= n; i++) cin >> A[i];
 	Node* init_ver = createNode();
 	build(init_ver, 1, n);
 	version.push_back(init_ver);
 	for (int i = 1; i <= q; i++) {
 	    int type;
 	    cin >> type;
 	   	if (type == 3) {
 	   	    int k;
 	   	    cin >> k;
 	   	    k--;
 	   	    Node* new_ver = createNode();
 	   	    *new_ver = *version[k];
 	   	    version.push_back(new_ver);
 	   	} else if (type == 1) {
 			int k, pos;
 			ll val;
 			cin >> k >> pos >> val;
 			update(version[k-1], 1, n, pos, val);	   	 	
 	   	} else {
 	   	 	int k, a, b;
 	   	 	cin >> k >> a >> b;
 	   	 	cout << get_sum(version[k-1], 1, n, a, b) << endl;
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



















