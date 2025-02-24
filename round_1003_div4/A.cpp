/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 18.02.2025 16:36:52
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

string str;

void solve(void) {
	cin >> str;
	int len = str.size();
	if (len < 2) {
	 	cout << str << endl;
	 	return;
	}
	string temp = str.substr(len-2,2);
	if (temp == "us") {
		string ret = str.substr(0,len-2) + "i";
		cout << ret << endl;
		return;
	}
	cout << str << endl;
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
