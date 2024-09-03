#include <bits/stdc++.h>
#define ll long long

#ifdef HOANG_DEBUG
#include <time.h>
#include <stdio.h>
 
double time1, timedif;
#endif // HOANG_DEBUG

using namespace std;

const ll M = 1e5 * 2;
const ll N = 1e2 * 5 + 1;
const ll MOD = 1e9+7;
int n;
ll dp[N][M];

ll bin(const ll a, ll b) {
    if (b == 0) return 1;
    ll temp = bin(a, b >> 1);
    temp *= temp;
    temp %= MOD;
    if (b & 1) return (temp * a) % MOD;
    return temp;
}

void solve(void) {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += i;
    if (sum % 2 != 0) {
        cout << 0 << endl;
        return;
    }

    sum /= 2;
    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= 1; j--) {
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= MOD;
            if (j - i >= 0) {
                dp[i][j] += dp[i-1][j-i];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << (dp[n][sum] * bin(2, MOD-2)) % MOD << endl;
}
  
int main(void) {
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
