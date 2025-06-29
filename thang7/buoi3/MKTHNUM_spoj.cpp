#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
  	int cnt;
  	Node* left;
  	Node* right;
};
const ll N = 1e5+10;
int n, m;
vector<pair<int,int>> save;
vector<Node*> version;
int level[N], ans[N];

bool cmp(pair<int,int> a, pair<int,int> b) {
 	if (a.first == b.first) return a.second < b.second;
 	return a.first < b.first;
}

Node* createNode(void) {
 	Node* ret = new Node();
 	ret->left = nullptr;
 	ret->right = nullptr;
 	ret->cnt = 0;
 	return ret;
}

void build(Node* &root, int left, int right) {
    root = createNode();
    if (left == right) return;
    int mid = (left+right)/2;
	build(root->left, left, mid);
	build(root->right, mid+1, right);
	root->cnt = root->left->cnt + root->right->cnt;
}	

void update(Node* &root, int left, int right, int pos) {
 	if (left == right) {
 	 	root = createNode();
 	 	root->cnt++;
 	 	return;
 	}
 	Node* temp = createNode();
 	*temp = *root;
 	int mid = (left+right)/2;
 	if (pos <= mid) {
 	 	update(temp->left, left, mid, pos);
 	} else {
 	 	update(temp->right, mid+1, right, pos);
 	}
 	root = temp;
 	root->cnt = root->left->cnt + root->right->cnt;
}

int get_idx(Node* rootLeft, Node* rootRight, int left, int right, int k) {
	if (left == right) return left;
	int numb = rootRight->left->cnt - rootLeft->left->cnt;
	int mid = (left+right)/2;
	if (numb >= k) {
	 	return get_idx(rootLeft->left, rootRight->left, left, mid, k);
	}
	return get_idx(rootLeft->right, rootRight->right, mid+1, right, k-numb);
}

void solve(void) {
 	cin >> n >> m;
 	for (int i = 1; i <= n; i++) {
 		int temp;
		cin >> temp;
		save.push_back({temp,i});
 	}
 	sort(save.begin(), save.end(), cmp);
 	for (int i = 0; i < save.size(); i++) {
 	    level[save[i].second] = i+1;
 	    // compress number to 1->n
 	    ans[i+1] = save[i].first;
 	}	
 	Node* version0;
 	build(version0, 1, n);
 	version.push_back(version0);
 	for (int i = 1; i <= n; i++) {
 	 	Node* newVersion = createNode();
 	 	*newVersion = *version.back();
 	 	update(newVersion, 1, n, level[i]);
 	 	version.push_back(newVersion);
 	}
 	for (int i = 1; i <= m; i++) {
 	 	int u, v;
 	 	int k;
 	 	cin >> u >> v >> k;
 	 	int idx = get_idx(version[u-1], version[v], 1, n, k);
 	 	cout << ans[idx] << endl;
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


















