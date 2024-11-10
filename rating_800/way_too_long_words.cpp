#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	string str;
	cin >> str;
	if (str.size() <= 10) {
		cout << str << endl;
		return;
	}

	cout << str[0] << str.size() - 2 << str[str.size()-1] << endl;
}
  
int main(void) {
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




