#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e4+1;
int A[N];

void solve(void) {
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n-1; i++) cin >> A[i];
	int idx = 1;
	while (idx < n) {
		idx += A[idx];
		if (idx == t) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
	
    return 0;
}



