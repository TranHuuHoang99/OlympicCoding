/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 12.02.2025 20:55:32
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
const int max_val = 1e5;
int n;
int cost[6] = {0,1,5,10,20,100};
int dp[6][N];

void solve(void) {
	cin >> n;
	int temp = 0;
	int ret = 0;
	if (n >= 1e5) {
	 	temp = n % max_val;
	 	n /= max_val;
	 	ret = n * 1e3;
	} else {
	 	temp = n;
	}
	for (int i = 0; i <= 5; i++) {
	 	for (int j = 0; j <= temp; j++) {
	 	 	if (j == 0) {
	 	 	 	dp[i][j] = 0;
	 	 	} else {
	 	 	 	dp[i][j] = INT32_MAX;
	 	 	}
	 	}
	}
	for (int i = 1; i <= 5; i++) {
	 	for (int j = 1; j <= temp; j++) {
	 	 	dp[i][j] = min(dp[i][j], dp[i-1][j]);
	 	 	if (j >= cost[i]) {
	 	 	 	dp[i][j] = min(dp[i][j], dp[i][j-cost[i]] + 1);
	 	 	}
	 	}
	}
	ret += dp[5][temp];
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
