#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+1;
int A[N];
ll n, m, a;

void solve(void) {
	cin >> n >> m >> a;
	if (m < n) swap(m,n);
	if (m <= a) {
		cout << 1 << endl;
		return;
	}

	ll temp = -1;
	if (m % a == 0) {
		temp = m / a;
	} else {
		temp = m / a + 1;
	}
	
	if (n > a) {
		if (n % a == 0) {
			temp *= (n/a);
		} else {
			temp *= (n/a+1);
		}
	}
	cout << temp << endl;	
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
	
    return 0;
}


