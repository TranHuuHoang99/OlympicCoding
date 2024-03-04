#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<ll> dp(1e7, -1);

ll solve(const ll &value) {
    if(value < 1e7 && dp[value] != -1) {
        return dp[value];
    }

    ll temp = value;

    if(value/4 > 2) {
        temp = max(value, solve(value/2) + solve(value/3) + solve(value/4));
    }

    if(value < 1e7) {
        dp[value] = temp;
    }
    
    return temp;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll value = 0;
    while(cin >> value) {
        cout << solve(value) << endl;
    }

    return 0;
}
