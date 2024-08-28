#include <bits/stdc++.h>
#define ll long long

#ifdef HOANG_DEBUG
#include <time.h>
#include <stdio.h>
 
double time1, timedif;
#endif // HOANG_DEBUG

using namespace std;

const ll N = 1e6+1;
const ll MOD = 1e9+7;
int memo[N];
int n;

ll recur(int next) {
    if (next == 0) return 1;
    if (next < 0) return 0;
    if (memo[next] != -1) return memo[next];

    ll temp = 0;
    for (int i = 1; i <= 6; i++) {
        temp += recur(next-i);
        temp %= MOD;
    }

    return memo[next] = temp;
}

void solve(void) {
    cin >> n;
    memset(memo, -1, sizeof(memo));
    cout << recur(n) << endl;
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
