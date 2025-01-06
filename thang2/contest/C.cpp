/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 06.01.2025 20:28:59
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int fibo(int n) {
 	if (n <= 1) return n;
 	return fibo(n-1) + fibo(n-2);
}

void solve(void) {
	int n;
	cin >> n;
	cout << fibo(n) << endl;	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
