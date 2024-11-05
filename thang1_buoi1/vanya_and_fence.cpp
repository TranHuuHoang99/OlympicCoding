#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+1;
int A[N];
int n;

void solve(void) {
	int n, h;
	cin >> n >> h;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		ret += temp <= h ? 1 : 2;
	}

	cout << ret << endl;
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
	
    return 0;
}

