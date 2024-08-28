#include <bits/stdc++.h>
#define ll long long

#ifdef HOANG_DEBUG
#include <time.h>
#include <stdio.h>
 
double time1, timedif;
#endif // HOANG_DEBUG

using namespace std;

void solve(void) {
    int n, x;
    cin >> n >> x;
    vector<int> c(n+1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    vector<vector<int>> dp(2, vector<int>(x+1, INT32_MAX));

    for (int i = 0; i <= 1; i++) dp[i][0] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[1][j] = min(dp[1][j], dp[0][j]);
            if (j - c[i] >= 0 && dp[1][j-c[i]] != INT32_MAX) {
                dp[1][j] = min(dp[1][j], dp[1][j-c[i]]+1);
            }
        }

        swap(dp[1], dp[0]);
        fill(dp[1].begin(), dp[1].end(), INT32_MAX);
        dp[1][0] = 0;
    }

    if (dp[0][x] == INT32_MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[0][x] << endl;
    }
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
	freopen("input.txt", "r", stdin);
    time1 = (double)clock();
    time1 = time1 / CLOCKS_PER_SEC; 
#endif //HOANG_DEBUG

    //write your code here
    solve();

#ifdef HOANG_DEBUG
    timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
    printf("The elapsed time is %lf seconds\n", timedif);
#endif //HOANG_DEBUG

    return 0;
}
