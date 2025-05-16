#include <bits/stdc++.h>
#define ll long long

using namespace std;

char A[30][30];
int n, m;

void init(void) {
 	for (int i = 0; i <= 25; i++) {
 	 	for (int j = 0; j <= 25; j++) {
 	 	 	A[i][j] = 0;
 	 	}
 	}
}

void solve(void) {
	init();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= m; j++) {
	     	cin >> A[i][j];
	    }
	}
	for (int i = n; i > 1; i--) {
	 	for (int j = 1; j <= m; j++) {
			if (A[i][j] != '?' && A[i-1][j] == '?') {
			 	A[i-1][j] = A[i][j];
	 	 	}
	 	}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
		 	if (A[i][j] != '?' && A[i+1][j] == '?') {
		 	 	A[i+1][j] = A[i][j];
		 	}
	 	}
	}
	for (int i = 1; i <= n; i++) {
	 	for (int j = m; j > 1; j--) {
	 	 	if (A[i][j] != '?' && A[i][j-1] == '?') {
	 	 	 	A[i][j-1] = A[i][j];
	 	 	}
	 	}
	}
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j < m; j++) {
	 	 	if (A[i][j] != '?' && A[i][j+1] == '?') {
	 	 	 	A[i][j+1] = A[i][j];
	 	 	}
	 	}
	}
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) cout << A[i][j];
	 	cout << endl;
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

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
	 	solve();
	}

	return 0;
}

