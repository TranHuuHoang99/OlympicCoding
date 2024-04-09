#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N, W;
vector<int> weight;
vector<ll> profit;
vector<vector<ll>> dp(100+1, vector<ll>(1e5+1, -1));

ll solve(int i, int cur_w) {
    if(i >= N) return 0;

    if(dp[i][cur_w] != -1) return dp[i][cur_w];

    ll take = -1e15;
    if(cur_w + weight[i] <= W) {
        take = profit[i] + solve(i+1, cur_w+weight[i]);
    }

    ll not_take = solve(i+1, cur_w);

    ll temp = max(take, not_take);
    dp[i][cur_w] = temp;

    return temp;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> W;
    weight.assign(N, 0);
    profit.assign(N, 0);

    for(int i = 0; i < N; i++) cin >> weight[i] >> profit[i];

    cout << solve(0,0) << endl;

    return 0;
}
