#include <bits/stdc++.h>
#define ll long long

#ifdef HOANG_DEBUG
#include <time.h>
#include <stdio.h>
 
double time1, timedif;
#endif // HOANG_DEBUG

using namespace std;

const ll N = 1e3*5 + 1;
ll x[N];
int n;
ll dp[N][N];

void solve(void) {
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
        dp[i][i] = x[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            dp[j][i] = max(x[j] - dp[j+1][i], x[i] - dp[j][i-1]);
        }
    }

    cout << (dp[0][n-1] + sum) / 2 << endl;
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
