/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 21.01.2025 20:19:07
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e3+10;
int n, p, k, r, s;
bool A[N], B[N];

int value(int pos, bool isKa, bool isKb) {
	int ret = 0;
	if ((A[pos] && isKa) || (B[pos] && isKb)) ret = 1;
	return ret;
}	

void updateMax(int& a, int b) {
 	a = max(a, b);
}

void solve(void) {
 	cin >> n >> p >> k;
 	cin >> r;
 	for (int i = 1; i <= r; i++) {
 	 	int temp;
 	 	cin >> temp;
		A[temp] = true;
 	}
 	cin >> s;
 	for (int i = 1; i <= s; i++) {
 	 	int temp;
 	 	cin >> temp;
 	 	B[temp] = true;
 	}
	if (p > 2*n/k) {
	 	int ret = 0;
		for (int i = 1; i <= n; i++) {
		 	ret += value(i, true, true);
		}
		cout << ret << endl;
		return;
	}
	vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(p+1));
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= p; j++) {
	 	 	dp[i][j].resize(k+1);
	 	}
	}
	for (int i = 0; i <= n; i++) {
	 	for (int j = 0; j <= p; j++) {
	 	 	for (int ka = 0; ka <= k; ka++) {
	 	 	 	dp[i][j][ka].resize(k+1, -1);
	 	 	}
	 	}
	}
	// initialize array with no question, no glance, no glance A and no glance B
	dp[0][0][0][0] = 0;
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j <= p; j++) {
	        for (int ka = 0; ka <= k; ka++) {
	         	for (int kb = 0; kb <= k; kb++) {
	         	 	if (dp[i][j][ka][kb] == -1) continue;
	         	 	int nextA = (ka == 0 || ka == k) ? 0 : ka+1;
	         	 	int nextB = (kb == 0 || kb == k) ? 0 : kb+1;
	         	 	// no open new glance
					updateMax(dp[i+1][j][nextA][nextB], dp[i][j][ka][kb] + value(i+1, nextA > 0, nextB > 0));
					if (j+1 <= p) {
						// open new glance from person B
					 	updateMax(dp[i+1][j+1][nextA][1], dp[i][j][ka][kb] + value(i+1, nextA > 0, true));
					 	// open new glance from person A
					 	updateMax(dp[i+1][j+1][1][nextB], dp[i][j][ka][kb] + value(i+1, true, nextB > 0));
					}
					if (j+2 <= p) {
						// open new glance both person A and B
					 	updateMax(dp[i+1][j+2][1][1], dp[i][j][ka][kb] + value(i+1, true, true));
					}
	         	}
	        }
	    }	
	}	
	int ret = INT32_MIN;
	for (int ka = 0; ka <= k; ka++) {
	 	for (int kb = 0; kb <= k; kb++) {
	 	 	ret = max(ret, dp[n][p][ka][kb]);
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










