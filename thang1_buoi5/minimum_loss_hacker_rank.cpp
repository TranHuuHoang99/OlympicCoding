#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5+1;
ll A[N];
int n;

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	ll ret = LLONG_MAX;
	set<ll> temp;
	for (int i = 0; i < n; i++) {
		auto it = temp.upper_bound(A[i]);
		if (it != temp.end()) {
			ll val = *it;
			ret = min(ret, val-A[i]);
		}
		temp.insert(A[i]);
	}
	cout << ret << endl;
}
  
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
	
    return 0;
}

