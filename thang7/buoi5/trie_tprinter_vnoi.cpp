#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Trie {
  	Trie* node[26];
  	bool isLongest;
  	int numb;
};
const ll N = 1e5+10;
string S[N];
string max_str = "";
int n, pos;
string ans = "";
int numbWords;

Trie* createNode(void) {
 	Trie* ret = new Trie();
 	for (int i = 0; i < 26; i++) ret->node[i] = nullptr;
 	ret->isLongest = false;
 	ret->numb = 0;
 	return ret;
}

void addStr(Trie* root, const string& str, bool isLongest) {
 	Trie* temp = root;
 	for (char c : str) {
 	 	if (temp->node[c-'a'] == nullptr) {
 	 	 	temp->node[c-'a'] = createNode();
 	 	}
 	 	temp = temp->node[c-'a'];
 	 	temp->isLongest = isLongest;
 	}
 	temp->numb++;
}

void dfs(Trie* root) {
 	for (int i = 1; i <= root->numb; i++) {
 		ans += 'P';	
 		numbWords++;
 		if (numbWords == n) {
 		 	cout << ans.size() << endl;
 		 	cout << ans << endl;
 		 	exit(0);
 		}
 	}
 	char last_char = '$';
 	for (int i = 0; i < 26; i++) {
 	 	if (root->node[i] == nullptr) continue;
 	 	if (root->node[i]->isLongest == true) {
 	 	 	last_char = char(i+'a');
 	 	 	break;
 	 	}
 	}
 	for (int i = 0; i < 26; i++) {
 	 	if (root->node[i] == nullptr || char(i+'a') == last_char) continue;
 	 	ans += char(i+'a');
 	 	dfs(root->node[i]);
 	 	ans += '-';
 	}
 	if (last_char != '$') {
 	 	ans += last_char;
 	 	dfs(root->node[last_char-'a']);
 	}
}

void solve(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
	 	cin >> S[i];
	 	if (max_str.size() < S[i].size()) {
	 	 	max_str = S[i];
	 	 	pos = i;
	 	}
	}
	Trie* root = createNode();
	for (int i = 1; i <= n; i++) {
	 	if (i == pos) continue;
	 	addStr(root, S[i], false);
	}
	addStr(root, S[pos], true);
	numbWords = 0;
	dfs(root);
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


