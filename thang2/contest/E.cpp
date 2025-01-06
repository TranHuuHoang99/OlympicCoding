/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 06.01.2025 20:40:22
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

string cmp(string s) {
 	if (s.length() % 2 == 1) return s;
 	string s1 = cmp(s.substr(0,s.length()/2));
 	string s2 = cmp(s.substr(s.length()/2, s.length()));
 	if (s1 < s2) return s1 + s2;
 	return s2 + s1;
}

void solve(void) {
	string str1, str2;
	cin >> str1 >> str2;
	if (cmp(str1) == cmp(str2)) {
	 	cout << "YES" << endl;
	} else {
	 	cout << "NO" << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
