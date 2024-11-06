#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n, b, h, w;
	while (cin >> n >> b >> h >> w) {
		int ret = INT32_MAX;
		for (int i = 0; i < h; i++) {
			int p;
			cin >> p;
			for (int j = 0; j < w; j++) {
				int a;
				cin >> a;
				if (a >= n && p*n <= b) {
					ret = min(ret, p*n);
				}
			}
		}
		if (ret == INT32_MAX) {
			cout << "stay home" << endl;
		} else {
			cout << ret << endl;
		}
	}
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
	
    return 0;
}



