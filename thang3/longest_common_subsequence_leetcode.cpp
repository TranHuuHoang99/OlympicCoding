/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 08.01.2025 16:35:27
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
  		int len1 = text1.length();
  		int len2 = text2.length();
  		vector<vector<int>> dp(len1+1, vector<int>(len2+1));
  		for (int i = 1; i <= len1; i++) {
  		 	for (int j = 1; j <= len2; j++) {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				if (text1[i-1] == text2[j-1]) {
				 	dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
				}
  		 	}
        }
        return dp[len1][len2];
    }
};

void solve(void) {
	string text1;
	string text2;
	cin >> text1 >> text2;
	Solution s;
	cout << s.longestCommonSubsequence(text1, text2) << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();

	return 0;
}
