/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 07.01.2025 18:20:56
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
const ll MOD = 1e9+7;
ll A[N];
ll B[N];
int n;

ll f(ll a, ll b) {
 	if (b == 0) return 1;
 	if (b % 2 == 0) {
 	 	ll temp = f(a, b/2);
 	 	return (temp * temp) % MOD;
 	}
 	return (f(a, b-1) * a) % MOD;
}

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
	 	cin >> A[i] >> B[i];
	}
	for (int i = 0; i < n; i++) {
	 	cout << f(A[i],B[i]) % MOD << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
