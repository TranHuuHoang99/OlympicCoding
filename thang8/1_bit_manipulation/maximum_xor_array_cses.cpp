#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Trie {
  	Trie* node[2];
};
const ll N = 2e5+10;
int n;
int A[N], prefixXor[N];

Trie* createNode(void) {
    Trie* ret = new Trie();
    for (int i = 0; i <= 1; i++) ret->node[i] = nullptr;	
	return ret;
}	

void addTrie(Trie* root, int val) {
    Trie* temp = root;
	for (int i = 31; i >= 0; i--) {
	 	int mask = int(val & (1 << i)) > 0;
	 	if (temp->node[mask] == nullptr) {
	 	 	temp->node[mask] = createNode();
	 	}
	 	temp = temp->node[mask];	
	}
}	

int searchTrie(Trie* root, int val) {
    int ret = 0;
    Trie* temp = root;
    for (int i = 31; i >= 0; i--) {
     	int mask = int(val & (1 << i)) > 0;
     	if (temp->node[!mask] != nullptr) {
     	    ret |= (1 << i);
     	    temp = temp->node[!mask];
     	} else {
     	 	temp = temp->node[mask];
     	}
	}
    return ret;
}	

void solve(void) {
 	cin >> n;
 	for (int i = 1; i <= n; i++) cin >> A[i];
 	for (int i = 1; i <= n; i++) {
 	 	prefixXor[i] = prefixXor[i-1] ^ A[i];
 	}
 	Trie* root = createNode();
 	addTrie(root, 0);
 	int ret = 0;
 	for (int i = 1; i <= n; i++) {
 	 	ret = max(ret, searchTrie(root, prefixXor[i]));
 	 	addTrie(root, prefixXor[i]);
 	}	
 	cout << ret << endl;
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

