#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Trie {
  	Trie* node[2];
  	int idx;
};
const ll N = 2e5+10;
int A[N];
int n, k;

Trie* createNode(void) {
 	Trie* ret = new Trie();
 	for (int i = 0; i <= 1; i++) ret->node[i] = nullptr;
 	ret->idx = -1;
 	return ret;
}

void addNode(Trie* root, int val, int idx) {
 	Trie* temp = root;
 	for (int i = 31; i >= 0; i--) {
 	 	int bitMask = (val & (1 << i)) > 0;
 	 	if (temp->node[bitMask] == nullptr) {
 	 	 	temp->node[bitMask] = createNode();
 	 	}
 	 	temp = temp->node[bitMask];
 	 	temp->idx = idx;
 	}
}

int dfs(Trie* root, int next_bit, int val) {
 	if (next_bit < 0) {
 	 	return root->idx;
 	}
 	Trie* temp = root;
	int ret = -1;
	int mask_k = (k & (1 << next_bit)) > 0;
	int mask_val = (val & (1 << next_bit)) > 0;
	if (mask_k == 1) {
	 	if (temp->node[!mask_val] == nullptr) return -1;
	 	ret = max(ret, dfs(temp->node[!mask_val], next_bit-1, val));
    } else {
     	if (temp->node[!mask_val] != nullptr) {
     		ret = max(ret, temp->node[!mask_val]->idx);
     	}
     	if (temp->node[mask_val] != nullptr) {
     	 	ret = max(ret, dfs(temp->node[mask_val], next_bit-1, val));
     	}
    }                                                    
	return ret;
}

void solve(void) {
 	cin >> n >> k;
 	for (int i = 1; i <= n; i++) cin >> A[i];
 	Trie* root = createNode();
 	int ret = INT32_MAX;
 	for (int i = 1; i <= n; i++) {
 		addNode(root, A[i], i);
 	 	int temp = dfs(root, 31, A[i]);
 	 	if (temp != -1) {
 	 	 	ret = min(ret, i-temp+1);
 	 	}
 	}
 	cout << (ret == INT32_MAX ? -1 : ret) << endl;
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

