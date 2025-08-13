/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-08-13 22:19:07 
************************************************************************** 
*/
// giai thich ve loi giai cua bai nay o file ly thuyet buoi so 2
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 20;
const int max_mask = (1 << 16) + 10;
const int max_card = 120 + 10; // if N is full of red or blue the total of token is 0 + 1 + .. + 15 = 120
int n;
pair<char,pair<int,int>> A[20];
int dp[max_mask][max_card]; // the maximum collect token operation due to red card
int sumRed = 0;
int sumBlue = 0;

void solve(void) {
	for (int mask = 0; mask < (1 << 16); mask++) {
	 	for (int collect = 0; collect <= 120; collect++) {
	 	 	dp[mask][collect] = -1;
	 	}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
	    cin >> A[i].first >> A[i].second.first >> A[i].second.second;
	    sumRed += A[i].second.first;
	    sumBlue += A[i].second.second;
	}
	dp[0][0] = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		int numbRed = 0;
		int numbBlue = 0;
		for (int i = 0; i < n; i++) {
		 	if (mask & (1 << i)) {
		 	 	if (A[i].first == 'R') {
		 	 	 	numbRed++;
		 	 	} else {
		 	 	 	numbBlue++;
		 	 	}
		 	}
		}
	 	for (int collect = 0; collect <= 120; collect++) {
	 		if (dp[mask][collect] == -1) continue;
	 	 	for (int i = 0; i < n; i++) {
	 	 	 	if (!(mask & (1 << i))) {
	 	 	 		int costRed = A[i].second.first;
	 	 	 		int costBlue = A[i].second.second;
	 	 	 	 	dp[mask|(1<<i)][collect+min(costRed,numbRed)] = max(dp[mask|(1<<i)][collect+min(costRed,numbRed)], dp[mask][collect] + min(costBlue, numbBlue));
	 	 	 	}
	 	 	}
	 	}
	}
	int ret = 1e9+10;
	for (int collect = 0; collect <= 120; collect++) {
	 	if (dp[(1<<n)-1][collect] != -1) {
	 	    int collectTokenSteps = max(sumRed - collect, sumBlue - dp[(1<<n)-1][collect]);
	 	    ret = min(ret, collectTokenSteps);
	 	}	
	}
	cout << ret + n << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

