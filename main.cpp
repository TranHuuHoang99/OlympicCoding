#include <bits/stdc++.h>
#define ll long long

#ifdef HOANG_DEBUG
#include <time.h>
#include <stdio.h>
 
double time1, timedif;
#endif // HOANG_DEBUG

using namespace std;

const ll N = 1e5+1;
ll x[101];
int n;
bool dp[101][N];

void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 1e5; j++) {
            dp[i][j] |= dp[i-1][j];
            if (j - x[i] >= 0) dp[i][j] |= dp[i-1][j-x[i]];
        }
    }

    set<int> ret;
    for (int i = 1; i <= 1e5; i++) {
        if (dp[n][i]) ret.insert(i);
    }

    cout << ret.size() << endl;
    for (auto r : ret) cout << r << ' ';
    cout << '\n';
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
