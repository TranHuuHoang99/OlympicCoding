#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+1;
int A[N];
int n;

void solve(void) {
	int n;
	cin >> n;
	if (n == 2) {
		cout << "NO" << endl;
		return;
	}
	cout << (n%2 ? "NO" : "YES") << endl;	
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
	
    return 0;
}


