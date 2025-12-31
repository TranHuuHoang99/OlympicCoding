/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 13.12.2024 22:55:25
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+1;
ll A[110][110];
char C[N][2];

void solve(void) {
	memset(A,0,sizeof(A));
	memset(C,0,sizeof(C));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
	 	cin >> C[i];
	 	int ver = C[i][0];
	 	int hor = C[i][1];
	 	for (int j = 'a'; j <= 'k'; j++) {
	 	 	if (j != hor) {
	 	 	 	A[ver][j]++;
	 	 	}
	 	 	if (j != ver) {
	 	 	 	A[j][hor]++;
	 	 	}
	 	}
	}
	ll ret = 0;
	for (int i = 0; i < n; i++) {
	 	int ver = C[i][0];
	 	int hor = C[i][1];
	 	ret += A[ver][hor];
	}
	cout << ret / 2 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG

	int t;
	cin >> t;
	while (t--) {
	 	solve();
	}

	return 0;
}
