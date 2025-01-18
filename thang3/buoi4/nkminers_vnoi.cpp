/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 18.01.2025 21:03:50
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+100;
int n;
/*
	first array is next food, second array is the last food of mine,
	third array is second type of food of other mine
	fourth array is third type of food of other mine
	................................................
	mine 1:
	food_type, A, next_food_type.
	mine 2:
	food_type, B, C.
	................................................
	array of 4 include : 0 is no_food, 1 is M, 2 is F, 3 is B
*/
//     N  i  B  C
//        C  A  i
int dp[N][4][4][4];
int food[N];

int cal(int a, int b, int c) {
 	int ret = 0;
 	if (a == 1 || b == 1 || c == 1) {
 		ret++;
 	}
 	if (a == 2 || b == 2 || c == 2) {
 	 	ret++;
 	}
 	if (a == 3 || b == 3 || c == 3) {
 	 	ret++;
 	}
 	return ret;
}

void solve(void) {
 	cin >> n;
 	for (int i = 1; i <= n; i++) {
 	 	char temp;
 	 	cin >> temp;
 	 	if (temp == 'M') {
 	 	 	food[i] = 1;
 	 	} else if (temp == 'F') {
 	 	 	food[i] = 2;
 	 	} else {
 	 	 	food[i] = 3;
 	 	}
 	}
 	for (int i = 0; i <= n; i++) {
 	 	for (int j = 0; j <= 3; j++) {
 	 	 	for (int k = 0; k <= 3; k++) {
 	 	 	 	for (int l = 0; l <= 3; l++) {
 	 	 	 	 	dp[i][j][k][l] = -1;
 	 	 	 	}
 	 	 	}
 	 	}
 	}
	dp[0][0][0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 3; j++) { // A
		 	for (int k = 0; k <= 3; k++) { // B
		 	 	for (int l = 0; l <= 3; l++) { // C
		 	 	 	if (dp[i][j][k][l] != -1) {
		 	 	 	 	// if next food move into first mine
		 	 	 	 	dp[i+1][food[i]][k][l] = max(dp[i+1][food[i]][k][l], dp[i][j][k][l] + cal(j, food[i], food[i+1]));
		 	 	 	 	// if next food move into second mine
		 	 	 	 	dp[i+1][l][j][food[i]] = max(dp[i+1][l][j][food[i]], dp[i][j][k][l] + cal(k, l, food[i+1]));
		 	 	 	}
		 	 	}
		 	}
		}
	}
	int ret = -1;
	for (int i = 0; i <= 3; i++) {
	 	for (int j = 0; j <= 3; j++) {
	 		for (int k = 0; k <= 3; k++) {
	 		 	ret = max(ret, dp[n][i][j][k]);
	 		}
		}
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




















