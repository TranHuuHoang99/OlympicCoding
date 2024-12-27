/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 28.12.2024 20:06:59
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int rc(int n) {
 	if (n == 0) return 0;
 	return n + rc(n-1);
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
