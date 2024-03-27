#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node {
    int weight;
    ll price;
    Node(int _weight = 0, ll _price = 0) :
    weight(_weight),
    price(_price) {}
};

int n = 0;
int max_weight = 0;
vector<Node> goods;
vector<vector<ll>> dp;

bool cmp(Node a, Node b) {
    return a.weight < b.weight;
}

ll solve(void) {
    for(int i = 1; i <= n; i++) {
        Node temp = goods[i];
        for(int j = 1; j <= max_weight; j++) {
            if(temp.weight > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], temp.price + dp[i-1][j-temp.weight]);
            }
        }
    }

    return dp[n][max_weight];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> max_weight;
    goods.assign(n+1, Node());
    dp.assign(n+1, vector<ll>(max_weight+1, 0));

    for(int i = 1; i <= n; i++) {
        cin >> goods[i].weight >> goods[i].price;
    }

    sort(goods.begin(), goods.end(), cmp);

    cout << solve() << endl;

    return 0;
}
