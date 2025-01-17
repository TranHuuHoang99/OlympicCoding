/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 16.01.2025 20:21:40
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 5e3+1;
string str;
// first array is character, second array is open brackets, last array is state
// state 0 is not into transform, state 1 is being transformed, state 2 is over transform
bool dp[N][N][3];

void solve(void) {
	cin >> str;
	int n = str.size();
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= n; j++) {
	 	 	for (int k = 0; k <= 2; k++) {
	 	 	 	dp[i][j][k] = false;
	 	 	}
	 	}
	}
	dp[0][0][0] = true;
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j <= i; j++) {
	 	 	for (int k = 0; k <= 2; k++) {
	 	 	 	if (dp[i][j][k] == false) continue;
	 	 	 	if (str[i] == '(') { // this is next bracket not current
	 	 	 	 	if (k == 0) { // 0 -> 0 or 0 -> 1
						dp[i+1][j+1][0] = true;
						if (j > 0) {
						 	dp[i+1][j-1][1] = true;
	 	 	 	 	 	}
	 	 	 		} else if (k == 1) { // 1 -> 1 or 1 -> 2
	 	 	 		 	if (j > 0) {
	 	 	 		 	 	dp[i+1][j-1][1] = true;
	 	 	 		 	}
	 	 	 		 	dp[i+1][j+1][2] = true;
	 	 	 		} else { // 2 -> 2
	 	 	 		 	dp[i+1][j+1][2] = true;
	 	 	 		}
	 	 	 	} else { // str[i] == ')'
					if (k == 0) { // 0 -> 0 or 0 -> 1
					 	if (j > 0) {
					 	 	dp[i+1][j-1][0] = true;
					 	}
					 	dp[i+1][j+1][1] = true;
					} else if (k == 1) { // 1 -> 1 or 1 -> 2
					 	dp[i+1][j+1][1] = true;
					 	if (j > 0) {
					 	 	dp[i+1][j-1][2] = true;
					 	}
					} else {
					 	if (j > 0) { // 2 -> 2
					 	 	dp[i+1][j-1][2] = true;
					 	}
					}
	 	 	 	}
	 	 	}
	 	}
	}
	for (int i = 0; i <= 2; i++) {
	 	if (dp[n][0][i]) {
	 	 	cout << "possible" << endl;
	 	 	return;
	 	}
	}
	cout << "impossible" << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
