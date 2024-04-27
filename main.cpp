#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> prices;
vector<int> res;
vector<int> dp;

void solve(vector<int> dp) {
    dp[0] = 0;
    for(int i = 0; i <= K; i++) {
        for(int j = 1; j <= K; j++) {
            if(i+j > K) break;
            if(prices[j] < 0) continue;
            if(dp[i] != 1001) {
                dp[i+j] = min(dp[i+j], dp[i] + prices[j]);
            }
        }
    }
    
    dp[K] = dp[K] == 1001 ? -1 : dp[K];
    res.push_back(dp[K]);
}   

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        cin >> N >> K;
        prices.assign(K+1,0);
        for(int i = 1; i <= K; i++) cin >> prices[i];
        dp.assign(K+1, 1001);
        solve(dp);
    }

    for(auto r : res) {
        cout << r << "\n";
    }

    return 0;
}
