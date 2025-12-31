/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 14.12.2024 21:49:06
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 210;
int matrix[N][N];
int n, m;

void solve(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < m; j++) {
	 	 	cin >> matrix[i][j];
	 	}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < m; j++) {
	 	 	int ver = i, hor = j, temp = matrix[ver][hor];
	 	 	--ver;
	 	 	--hor;
			while (ver >= 0 && hor >= 0) {
				temp += matrix[ver][hor];			 	
				ver--;
				hor--;
			}
			ver = i;
			hor = j;
			ver--;
			hor++;
			while (ver >= 0 && hor < m) {
			 	temp += matrix[ver][hor];
			 	ver--;
			 	hor++;
			}
			ver = i;
			hor = j;
			ver++;
			hor++;
			while (ver < n && hor < m) {
			 	temp += matrix[ver][hor];
			 	ver++;
			 	hor++;
			}
			ver = i;
			hor = j;
			ver++;
			hor--;
			while (ver < n && hor >= 0) {
			 	temp += matrix[ver][hor];
			 	ver++;
			 	hor--;
			}
			ret = max(ret, temp);
	 	}
	}
	cout << ret << endl;
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
