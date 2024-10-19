#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int m, n, k;
	cin >> m >> n >> k;

	vector<string> ret;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		string temp;
		for (char c : str) {
			for (int j = 0; j < k; j++) temp += c;
		}

		for (int j = 0; j < k; j++) ret.push_back(temp);
	}

	for (int i = 0; i < ret.size(); i++) cout << ret[i] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);

	solve();

	return 0;
}	


