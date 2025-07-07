#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Trie {
  	Trie* node[26];
  	bool isEnd;
};
const ll N = 5e3+10;
const ll  MOD = 1e9+7;
int n, k;
string pattern;
Trie* root;
ll dp[N];

Trie* createNode(void) {
 	Trie* ret = new Trie();
 	for (int i = 0; i < 26; i++) ret->node[i] = nullptr;
 	ret->isEnd = false;
 	return ret;
}

void addStr(const string& str) {
   	Trie* temp = root;
   	for (char c : str) {
   	 	if (temp->node[c-'a'] == nullptr) {
   	 	 	temp->node[c-'a'] = createNode();
   	 	}
   	 	temp = temp->node[c-'a'];
   	}
   	temp->isEnd = true;
}	

void solve(void) {
 	cin >> pattern;
 	root = createNode();
 	cin >> k;
 	for (int i = 1; i <= k; i++) {
 	 	string str;
 	 	cin >> str;
 	 	addStr(str);
 	}
 	int len = pattern.size();
 	dp[0] = 1ll;
 	for (int i = 0; i < len; i++) {
 	 	Trie* temp = root;
 	 	for (int j = i; j < len; j++) {
 	 	 	if (temp->node[pattern[j]-'a'] == nullptr) break;
 	 	 	temp = temp->node[pattern[j]-'a'];
 	 	 	if (temp->isEnd == true) {
 	 	 	 	(dp[j+1] += dp[i]) %= MOD;
 	 	 	}
 	 	}
 	}
 	cout << dp[len] << endl;
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

