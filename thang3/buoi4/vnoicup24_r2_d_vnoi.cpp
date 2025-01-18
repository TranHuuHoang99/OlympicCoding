/*
 ***************************************************************************
 *      * AUTHOR : hoangprodn
 *      * NICK   : thhoang08091999@gmail.com
 *      * CREATED: 23.01.2025 15:25:43
 ***************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5+10;
int n, k;
/*
	- first array is the next character to update
	- second array is number of character 'K' changed
	- third array is number of character 'O' changed
	- fourth array is the different between 'OK' and 'KO'
	notice that number of OK minus for KO is in range (-1,0,1)
	so we will translate it to (0,1,2) for array indexing in c++
	- fifth array is the last character of the string
	0 is empty, 1 is 'O', 2 is 'K'
*/
int dp[N][12][12][3][3];
string str;

void get_max(int& a, int b) {
 	a = max(a, b);
}

void solve(void) {
 	cin >> n >> k;
 	cin >> str;
 	for (int i = 0; i <= n; i++) {
 	 	for (int changeK = 0; changeK <= k; changeK++) {
 	 	 	for (int changeO = 0; changeO <= k; changeO++) {
 	 	 	 	for (int diff = 0; diff <= 2; diff++) {
 	 	 	 	 	for (int last = 0; last <= 2; last++) {
 	 	 	 	 	 	dp[i][changeK][changeO][diff][last] = -1;
 	 	 	 	 	}
 	 	 	 	}
 	 	 	}
 	 	}
 	}
 	/*
 	  	Notice: we initialze with the beginning value like so
 	  	- first array: we start from empty string
 	  	- second array: we have not change any character 'K' yet
 	  	- third array: we have not change any character 'O' yet
 	  	- fourth array: number of 'OK' and 'KO' are equal so different between them is 0
 	  	- fifth array: because of we start from empty string so the last character is empty -> mean 0
 	*/
 	dp[0][0][0][1][0] = 0;
 	for (int i = 0; i < n; i++) {
 	 	for (int changeK = 0; changeK <= k; changeK++) {
 	 	 	for (int changeO = 0; changeO <= k; changeO++) {
 	 	 	 	for (int diff = 0; diff <= 2; diff++) {
 	 	 	 	 	for (int last = 0; last <= 2; last++) {
 	 	 	 	 	 	if (dp[i][changeK][changeO][diff][last] == -1) continue;
 	 	 	 	 	 	if (last == 0) {
 	 	 	 	 	 	 	get_max(dp[i+1][changeK+(str[i]=='O')][changeO][diff][2], dp[i][changeK][changeO][diff][last]);
 	 	 	 	 	 	 	get_max(dp[i+1][changeK][changeO+(str[i]=='K')][diff][1], dp[i][changeK][changeO][diff][last]);	
 	 	 	 	 	 	} else if (last == 1) {
 	 	 	 	 	 	 	get_max(dp[i+1][changeK+(str[i]=='O')][changeO][diff+1][2], dp[i][changeK][changeO][diff][last]+1);
 	 	 	 	 	 	 	get_max(dp[i+1][changeK][changeO+(str[i]=='K')][diff][1], dp[i][changeK][changeO][diff][last]);
 	 	 	 	 	 	} else { // last == 2
 							get_max(dp[i+1][changeK+(str[i]=='O')][changeO][diff][2], dp[i][changeK][changeO][diff][last]);
 							get_max(dp[i+1][changeK][changeO+(str[i]=='K')][diff-1][1], dp[i][changeK][changeO][diff][last]+1);	 	 	 	 	 	 	
 	 	 	 	 	 	}
 	 	 	 	 	}
 	 	 	 	}
 	 	 	}
 	 	}
 	}
 	int ret = -1;
 	for (int change = 0; change <= k; change++) {
 	 	for (int diff = 1; diff <= 2; diff++) {
 	 	 	for (int last = 1; last <= 2; last++) {
 	 	 	 	if (dp[n][change][change][diff][last] == -1) continue;
 	 	 	 	/*
 	 	 	 	  	we will ignore -1 and only get value in between 0 and 1 are both the maximize
 	 	 	 	  	remember because our fourth array is length 3
 	 	 	 	  	0 is -1, 1 is 0, 2 is 1 => diff-1 is equal to 0 and 1
 	 	 	 	*/
 	 	 	 	ret = max(ret, (diff-1) * dp[n][change][change][diff][last]);
 	 	 	}
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
