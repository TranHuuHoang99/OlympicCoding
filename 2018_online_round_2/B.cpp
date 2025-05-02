#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
 	char cmd;
 	int start, end;
};

const ll Q = 1e4+10;
int n, q, m;
Node A[Q];

ll reverseTracking(int pos) {
 	ll ret = 0ll;
 	for (int i = q; i >= 1; i--) {
 	 	if (A[i].cmd == 'a') {
 	 	 	ret += 1ll * pos;
 	 	} else {
 	 	 	if (A[i].start <= pos && pos <= A[i].end) {
 	 	 	 	pos = A[i].start + A[i].end - pos;
 	 	 	}
 	 	}
 	}
 	return ret;
}

void solve(void) {
	cin >> n >> q >> m;
	for (int i = 1; i <= q; i++) {
	 	char cmd;
	 	cin >> cmd;
	 	if (cmd == 'a') {
	 	 	A[i].cmd = cmd;
	 	} else {
	 	 	A[i].cmd = cmd;
	 	 	int a, b;
	 	 	cin >> a >> b;
	 	 	A[i].start = a;
	 	 	A[i].end = b;
	 	}
	}
	for (int i = 1; i <= m; i++) {
	 	int temp;
	 	cin >> temp;
	 	cout << reverseTracking(temp) << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG	

	solve();

	return 0;
}

