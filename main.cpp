#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n = 0;
vector<ll> prices;
ll max_pay = 0;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    prices.assign(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> prices[i];
        max_pay += prices[i];
    }

    sort(prices.begin(), prices.end(), greater<ll>());

    for(int i = 0; i < n; i++) {
        if((i+1)%3 == 0) max_pay -= prices[i];
    }

    cout << max_pay << endl;

    return 0;
}
