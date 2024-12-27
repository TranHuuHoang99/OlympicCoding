/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 27.12.2024 20:18:23
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll rc(int a) {
 	if (a == 0) return 1;
 	return 2 * rc(a-1);
}

void solve(void) {
	int n;
	cin >> n;
	cout << rc(n) << endl;	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
