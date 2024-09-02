#include <bits/stdc++.h>
#define ll long long

#ifdef HOANG_DEBUG
#include <time.h>
#include <stdio.h>
 
double time1, timedif;
#endif // HOANG_DEBUG

using namespace std;

const ll N = 1e3*5 + 1;
int dp[N][N];
char f_in[N], s_in[N];

void solve(void) {
    string str1, str2;
    cin >> str1 >> str2;
    copy(str1.begin(), str1.end(), f_in+1);
    copy(str2.begin(), str2.end(), s_in+1);

    for (int i = 1; i <= str2.size(); i++) dp[0][i] = i;
    for (int i = 1; i <= str1.size(); i++) dp[i][0] = i;

    for (int i = 1; i <= str1.size(); i++) {
        for (int j = 1; j <= str2.size(); j++) {
            if (f_in[i] == s_in[j]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                int g_min = min(dp[i-1][j], dp[i-1][j-1]);
                g_min = min(g_min, dp[i][j-1]);
                dp[i][j] = g_min + 1;
            }
        }
    }

    cout << dp[str1.size()][str2.size()] << endl;
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
