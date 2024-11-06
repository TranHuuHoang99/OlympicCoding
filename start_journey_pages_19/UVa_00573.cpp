#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	float h, u, d, f;
	while (cin >> h >> u >> d >> f && h) {
		float minus = u * f / 100;
		float temp = 0;
		int ret = 1;
		while (temp >= 0 && temp < h) {
			temp += u;
			if (temp > h) break;
			temp -= d;
			if (temp < 0) break;
			if (u > 0) u -= minus;
			ret++;
		}
		if (temp < 0) {
			cout << "failure on day " << ret << endl;
		} else {
			cout << "success on day " << ret << endl;
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





