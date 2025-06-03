#include <bits/stdc++.h>
#define ll long long

using namespace std;

string str;
stack<int> st;

void solve(void) {
	while (!st.empty()) st.pop();
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
	 	if (st.empty()) cnt++;
	 	if (str[i] == '(') {
	 	 	st.push(i);
	 	} else {
	 	 	while (!st.empty()) {
	 	 	 	st.pop();
	 	 	 	break;
	 	 	}
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

