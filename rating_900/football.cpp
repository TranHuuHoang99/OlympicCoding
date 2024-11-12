#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	string str;
	cin >> str;
	for (char c = '0'; c <= '1'; c++) {
		int cnt = 0;
		for (int i = 0; i < str.size(); i++) {
			if (c == str[i]) {
				cnt++;
			} else {
				cnt = 0;
			}
			if (cnt >= 7) {
				cout << "YES" << endl;
				return;
			}
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




