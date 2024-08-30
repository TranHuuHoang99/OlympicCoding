#include <bits/stdc++.h>
#define ll long long

#ifdef HOANG_DEBUG
#include <time.h>
#include <stdio.h>
 
double time1, timedif;
#endif // HOANG_DEBUG

using namespace std;

const ll N = 1e6+10;
const ll M = 8;
const ll MOD = 1e9+7;
ll dp[N][M];

void gen(void) {
    for (int i = 0; i < 8; i++) dp[0][i] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 8; j++) {
            if (j == 0 || j == 2 || j == 3 || j == 5 || j == 7) {
                dp[i][j] = (
                    dp[i-1][0] +
                    dp[i-1][2] +
                    dp[i-1][3] +
                    dp[i-1][5] +
                    dp[i-1][6]
                ) % MOD;
            } else {
                dp[i][j] = (
                    dp[i-1][1] +
                    dp[i-1][4] +
                    dp[i-1][7]
                ) % MOD;
            }
        }
    }
}

void solve(void) {
    int n;
    cin >> n;
    cout << (dp[n-1][1] + dp[n-1][7]) % MOD << endl;
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
    int t = 0;
    cin >> t;
    gen();
    while (t--) {
        solve();
    }

#ifdef HOANG_DEBUG
    timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
    printf("The elapsed time is %lf seconds\n", timedif);
#endif //HOANG_DEBUG

    return 0;
}
