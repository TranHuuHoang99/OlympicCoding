/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 07.01.2025 19:33:18
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1000;
ll A[N];
int n;

ll fibo(int n) {
	if (A[n] != -1) return A[n];
 	if (n <= 1) return n;
 	A[n] = fibo(n-1) + fibo(n-2);
 	return A[n];
}

ll F[N];

void bottomUp(void) {
 	F[0] = 0;
 	F[1] = 1;
 	for (int i = 2; i <= n; i++) {
 	 	F[i] = F[i-1] + F[i-2];
 	}
 	cout << F[n] << endl;
}

void solve(void) {
	int n;
	cin >> n;
	memset(A,-1,sizeof(A));
	cout << fibo(n) << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
