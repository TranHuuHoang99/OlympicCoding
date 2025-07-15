#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e6+10;
int pi[N];
int k;
string pattern, text;
int n, m;

int kmp(void) {
	int ret = 0;
	k = 0;
	for (int i = 2; i <= m; i++) {
	 	while (k > 0 && text[k+1] != text[i]) {
	 	    k = pi[k];
	 	}
	 	if (text[k+1] == text[i]) {
	 	 	k = k + 1;
		}
		pi[i] = k;
	}
	k = 0;
	for (int i = 1; i <= n; i++) {
	    while (k > 0 && pattern[i] != text[k+1]) {
	        k = pi[k];
	    }
	    if (text[k+1] == pattern[i]) {
	     	k = k + 1;
		}
		if (k == m) {
		 	ret++;
		 	k = pi[k];
		}
	}	
	return ret;
}

void solve(void) {
	cin >> pattern >> text;
	n = pattern.size();
	m = text.size();
	pattern = " " + pattern;
	text = " " + text;
	int ret = kmp();
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

