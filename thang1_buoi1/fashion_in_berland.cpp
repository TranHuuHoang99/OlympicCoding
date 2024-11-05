#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+1;
int A[N];
int n;

void solve(void) {
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp == 1) count++;
	}
	if (n == 1) {
		cout << (count == 0 ? "NO" : "YES") << endl;
		return;
	}	
	cout << (count == n-1 ? "YES" : "NO") << endl;
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
	
    return 0;
}

