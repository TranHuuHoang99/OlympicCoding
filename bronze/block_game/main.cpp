#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 27;
int ret[N];

void solve(void) {
	int n;
	cin >> n;
	string a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		vector<int> str1(26, 0);
		vector<int> str2(26, 0);
		for (char c : a) str1[c-'a']++;
		for (char c : b) str2[c-'a']++;
		for (int j = 0; j < 26; j++) ret[j] += max(str1[j], str2[j]);
	}

	for (int i = 0; i < 26; i++) cout << ret[i] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);

	solve();

	return 0;
}	




