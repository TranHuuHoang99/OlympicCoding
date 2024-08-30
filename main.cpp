#include <bits/stdc++.h>
#define ll long long

#ifdef HOANG_DEBUG
#include <time.h>
#include <stdio.h>
 
double time1, timedif;
#endif // HOANG_DEBUG

using namespace std;

const ll MOD = 1e9+7;
int n, m;

void solve(void) {
    cin >> n >> m;
    vector<ll> x(n);
    vector<vector<ll>> dp(n, vector<ll>(m+2, 0));

    for (int i = 0; i < n; i++) cin >> x[i];

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (x[i] == 0) {
                for (int j = 1; j <= m; j++) dp[i][j] = 1;
            } else {
                dp[i][x[i]] = 1;
            }
        } else {
            if (x[i] == 0) {
                for (int j = 1; j <= m; j++) {
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
                }
            } else {
                dp[i][x[i]] = (dp[i-1][x[i]-1] + dp[i-1][x[i]] + dp[i-1][x[i]+1]) % MOD;
            }
        }
    }

    ll ret = 0;
    for (int i = 1; i <= m; i++) {
        ret = (ret + dp[n-1][i]) % MOD;
    }
    cout << ret << endl; 
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
