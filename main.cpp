#include <bits/stdc++.h>
#define ll long long

#ifdef HOANG_DEBUG
#include <time.h>
#include <stdio.h>
 
double time1, timedif;
#endif // HOANG_DEBUG

using namespace std;

const ll N = 1e6+1;

void solve(void) {
    int n;
    cin >> n;
    vector<int> dp(n+1, INT32_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int temp = i;
        int min_val = INT32_MAX;

        while (temp > 0) {
            if (i - temp%10 >= 0) {
                min_val = min(min_val, dp[i-temp%10]);
            }
            temp /= 10;
        }

        dp[i] = min_val+1;
    }

    cout << dp[n] << endl;
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
