#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	int n;
	cin >> n;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		if (a == '+' || b == '+' || c == '+') ret++;
		if (a == '-' || b == '-' || c == '-') ret--;
	}
	cout << ret << endl;
}
  
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}





