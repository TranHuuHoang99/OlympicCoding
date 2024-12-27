/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 27.12.2024 20:38:34
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void rc(int next, string str) {
	if (next == 1) {
	 	cout << str << endl;
	 	return;
 	}
	cout << str << endl;
	rc(next-1, str+"*"); 	
}

void solve(void) {
	int n;
	cin >> n;
	rc(n, "*");
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
