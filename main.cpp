#include <bits/stdc++.h>
#define ll long long

#ifdef HOANG_DEBUG
#include <time.h>
#include <stdio.h>
 
double time1, timedif;
#endif // HOANG_DEBUG

using namespace std;

const ll N = 1e2*5 + 1;
vector<vector<ll>> dp(N, vector<ll>(N, -1));
int a, b;

ll dfs(int n, int m) {
    if (n == m) return 0;
    if (dp[n][m] != -1) return dp[n][m];

    ll temp = LLONG_MAX;
    for (int i = 1; i <= n-1; i++) {
        temp = min(temp, dfs(n-i, m) + 1 + dfs(i, m));
    }

    for (int i = 1; i <= m-1; i++) {
        temp = min(temp, dfs(n, m-i) + 1 + dfs(n, i));
    }

    return dp[n][m] = temp;
}

void solve(void) {
    cin >> a >> b;

    cout << dfs(a,b) << endl;
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
