/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 02.12.2024 13:55:42
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+1;
int A[N][N];
int n;
bitset<1000> win[N];
bitset<1000> lose[N];

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < n; j++) {
	 	 	cin >> A[i][j];
	 	}
	}
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < n; j++) {
	 	 	if (A[i][j] == 1) {
	 	 	 	win[i].set(j,1);
	 	 	 	lose[j].set(i,1);
	 	 	}
	 	}
	}
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < n; j++) {
	 		if (A[i][j] == 1) {
	 		 	bitset<1000> temp = win[j] & lose[i];
	 		 	if (temp.count() > 0) {
	 		 	 	for (int k = 0; k < n; k++) {
	 		 	 	 	if (i != j && j != k && k != i && temp[k] == 1) {
							cout << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
							return;
	 		 	 	 	}
	 		 	 	}
	 		 	}
	 		}
	 	}
	}
	cout << -1 << ' ' << -1 << ' ' << -1 << endl;
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
