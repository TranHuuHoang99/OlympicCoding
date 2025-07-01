#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e6+10;
struct TrieNode {
  	bool isEnd;
  	int val;
  	vector<TrieNode*> child;
};
int n, q;
string S[N];
int A[N];
TrieNode* root;

TrieNode* createNode(void) {
 	TrieNode* ret = new TrieNode();
 	ret->isEnd = false;
 	ret->val = -1;
 	ret->child.assign(26, nullptr);
 	return ret;
}

void add(const string& str, int val) {
	TrieNode* temp = root;
 	for (char c : str) {
 		if (temp->child[c-'a'] == nullptr) {
 		 	temp->child[c-'a'] = createNode();
 		}
 		temp = temp->child[c-'a'];
 		temp->val = max(temp->val, val);
	}
	temp->isEnd = true;	
}

int get(const string& str) {
 	TrieNode* temp = root;
 	for (char c : str) {
 	 	if (temp->child[c-'a'] == nullptr) return -1;
 	 	temp = temp->child[c-'a'];
 	}
 	return temp->val;
}

void solve(void) {
	cin >> n >> q;
	root = createNode();
	for (int i = 1; i <= n; i++) {
	 	cin >> S[i] >> A[i];
	 	add(S[i], A[i]);
	}
	for (int i = 1; i <= q; i++) {
	 	string str;
	 	cin >> str;
	 	cout << get(str) << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}

