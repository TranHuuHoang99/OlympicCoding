/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 25.01.2025 23:12:16
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e3+3;
string s, t;
int dp[N][N];

void solve(void) {
	cin >> s >> t;
	int n, m;
	n = s.size();
	m = t.size();
	s = " " + s;
	t = " " + t;
	for (int i = 1; i <= n; i++) {
	 	for (int j = 1; j <= m; j++) {
	 	 	if (s[i] == t[j]) {
	 	 	 	dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
	 	 	}
	 	 	dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
	 	}
	}
	int i = n, j = m;
	string ret = "";
	while (i) {
	 	if (s[i] == t[j]) {
			ret += s[i];
			i--;
			j--;	 	 	
	 	} else {
	 	 	if (dp[i][j] == dp[i-1][j]) {
	 	 	 	i--;
	 	 	} else {
	 	 	 	j--;
	 	 	}
	 	}
	}
	reverse(ret.begin(), ret.end());
	cout << ret << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
