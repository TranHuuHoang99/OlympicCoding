/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 06.12.2024 22:37:17
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+10;
ll A[N];
int n, q;

void solve(void) {
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> A[i];
	while (q--) {
	 	int a, b;
	 	cin >> a >> b;
	 	--a;
	 	--b;
	 	vector<ll> temp;
	 	for (int i = a; i < b; i++) {
	 	 	temp.push_back(abs(A[i]-A[i+1]));
	 	}
	 	if (temp.empty()) {
	 	 	cout << 0 << ' ';
	 	 	continue;
	 	}
	 	ll ret = temp[0];
	 	for (int i = 1; i < temp.size(); i++) {
			ret = __gcd(ret,temp[i]);         	
        }
        cout << ret << ' ';
	}
	cout << endl;
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
