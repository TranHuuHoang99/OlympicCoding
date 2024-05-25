#include <bits/stdc++.h>

#define ll long long
    
using namespace std;

vector<int> res;
  
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG
    
    int T;
    cin >> T;

    while(T--) {
        int M;
        ll X;
        cin >> M >> X;

        ll C;
        int H;
        int sum = 0;
        int ans = 0;
        vector<ll> dp(1e5+1, 1e18);
        dp[0] = 0;
        for(int i = 0; i < M; i++) {
            cin >> C >> H;
            sum += H;
            for(int j = sum; j >= H; j--) {
                if(dp[j-H]+C <= i*X) dp[j] = min(dp[j], dp[j-H]+C);
                if(dp[j] < 1e18) ans = max(ans, j);
            }
        }

        res.push_back(ans);
    }

    for(auto r : res) {
        cout << r << endl;
    }

    return 0;
}