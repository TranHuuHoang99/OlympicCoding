#include <bits/stdc++.h>
#define ll long long

#ifdef HOANG_DEBUG
#include <time.h>
#include <stdio.h>
 
double time1, timedif;
#endif // HOANG_DEBUG

using namespace std;

const ll MOD = 1e9 + 7;
const ll N = 1e6+1;
int n, x;
int c[101];
vector<vector<int>> dp(2, vector<int>(N, 0));

void solve(void) {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i <= 1; i++) dp[i][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[1][j] = dp[0][j];
            if (j - c[i] >= 0) {
                dp[1][j] += dp[1][j-c[i]];
            }
            dp[1][j] %= MOD;
        }

        swap(dp[0], dp[1]);
        fill(dp[1].begin(), dp[1].end(), 0);
        dp[1][0] = 1;
    }

    cout << dp[0][x] << endl;
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
