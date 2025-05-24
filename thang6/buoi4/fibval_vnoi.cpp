#include <bits/stdc++.h>
#define ll long long

using namespace std;

int u, v;
int fib[110];

void solve(void) {
	cin >> u >> v;
	u--;
	v--;
	int len = v-u+1;
	int ret = -1;
	if (len >= 32) {
	 	ret = len / 16 * 16;
	} else {
		u %= 32;
	 	for (int i = u; i < u+len-1; i++) {
	 	 	if (fib[i] == fib[i+1]) ret = 2;
	 	}
	}
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fib[0] = 1;
	fib[1] = 2;
	for (int i = 2; i <= 100; i++) {
	 	fib[i] = (fib[i-1] + fib[i-2]) % 7;
	}
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}
	return 0;
}


