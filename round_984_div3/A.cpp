#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 50+1;
int A[N];

void solve(void) {
    int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	
	bool valid = true;
	for (int i = 1; i < n; i++) {
		int temp = abs(A[i]-A[i-1]);
		if (temp != 5 && temp != 7) {
			valid = false;
			break;
		}
	}

	if (valid) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
  
int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}	

	return 0;
}


