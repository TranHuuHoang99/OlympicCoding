#include <bits/stdc++.h>
#define ll long long

using namespace std;

string str;

void solve(void) {
	cin >> str;
	stack<int> st;
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
		 	if (st.empty()) cnt++;
		 	st.push(i);
		} else {
		 	if (!st.empty()) st.pop();
		}
	}
	if (cnt > 1) {
	 	cout << "YES" << endl;
	} else {
	 	cout << "NO" << endl;
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

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}
 