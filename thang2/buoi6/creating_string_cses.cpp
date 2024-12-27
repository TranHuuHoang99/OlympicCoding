/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 28.12.2024 20:09:30
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

set<string> ret;
string str;

void back_track(string next, vector<bool> v) {
 	if (next.size() == str.size()) {
 	 	ret.insert(next);
 	 	return;
 	}
 	for (int i = 0; i < str.size(); i++) {
 	 	if (!v[i]) {
 	 	 	next += str[i];
 	 	 	v[i] = true;
 	 	 	back_track(next, v);
 	 	 	next.pop_back();
 	 	 	v[i] = false;
 	 	}
 	}
}

void solve(void) {
	cin >> str;
	vector<bool> v(str.size(), false);
	back_track("", v);
	cout << ret.size() << endl;
	for (string r : ret) {
	 	cout << r << endl;
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

	solve();

	return 0;
}
