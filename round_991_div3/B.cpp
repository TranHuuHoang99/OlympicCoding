/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 05.12.2024 21:53:51
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
ll A[N];
ll n;

void solve(void) {
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
	 	cin >> A[i];
	 	sum += A[i];
	}
	if (sum % n != 0) {
	 	cout << "NO" << endl;
	 	return;
	}
	sum /= n;
	ll temp = 0;
	ll cnt = 0;
	for (int i = 1; i <= n; i+=2) {
	 	temp += A[i];
	 	cnt++;
	}
	if (temp % cnt != 0 || temp / cnt != sum) {
	 	cout << "NO" << endl;
	 	return;
	}
	cout << "YES" << endl;
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
	while (t--) {
	 	solve();
	}

	return 0;
}
