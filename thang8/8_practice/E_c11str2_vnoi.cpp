/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-05 21:30:24 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5+10;
const ll prime = 1e9+7;
string A, B;
ll power_prime[N];
ll prefix_A[N];
ll prefix_B[N];

void solve(void) {
	cin >> A >> B;
	string origin1 = A;
	string origin2 = B;
	int n, m;
	n = A.size();
	m = B.size();
	A = " " + A;
	B = " " + B;
	power_prime[0] = 1ll;
	for (int i = 1; i <= 1e5; i++) {
	 	power_prime[i] = power_prime[i-1] * prime;
	}
	for (int i = 1; i <= n; i++) {
	    prefix_A[i] = prefix_A[i-1] + 1ll * int(A[i]-'a'+1) * power_prime[i-1];
	}	
	for (int i = 1; i <= m; i++) {
	 	prefix_B[i] = prefix_B[i-1] + 1ll * int(B[i]-'a'+1) * power_prime[i-1];
	}
	int idx = -1;
	for (int i = 1; i <= m; i++) {
	 	ll temp1 = prefix_A[n] - prefix_A[n-i];
	 	ll temp2 = prefix_B[i] * power_prime[n-i];
	 	if (temp1 == temp2) idx = i;
	}
	if (idx == -1) {
		origin1 += origin2;
		cout << origin1 << endl;
	} else {
		for (int i = idx+1; i <= m; i++) origin1 += B[i];
		cout << origin1 << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

