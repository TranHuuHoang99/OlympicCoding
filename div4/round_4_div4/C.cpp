/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 31.12.2024 21:46:41
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

char matrix[9][9];

void solve(void) {
	for (int i = 1; i <= 8; i++) {
	 	for (int j = 1; j <= 8; j++) {
	 	 	cin >> matrix[i][j];
	 	}
	}
	pair<int,int> ret = {0,0};
	bool valid = false;
	for (int i = 2; i <= 7; i++) {
	 	for (int j = 2; j <= 7; j++) {
			if (matrix[i][j] != '#') continue;
			if (matrix[i-1][j-1] != '#') continue;
			if (matrix[i-1][j+1] != '#') continue;
			if (matrix[i+1][j+1] != '#') continue;
			if (matrix[i+1][j-1] != '#') continue;
			ret = {i,j};
			valid = true;
			break;
	 	}
	 	if (valid) break;
	}
	cout << ret.first << ' ' << ret.second << endl;
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
