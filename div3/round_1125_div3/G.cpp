/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-12 20:17:34
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

struct connected_node {
    int u, v, price;
};
const int N = 1e5+10;
int n, m, q;
int root[N];
vector<connected_node> cn_arr;
int findRoot(int u) {
    if (u == root[u]) return u;
    return root[u] = findRoot(root[u]);
}
void solve(void) {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) root[i] = i;
    cn_arr.clear();
    int profit = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        cn_arr.push_back({u, v, d});
        profit += d;
    }
    sort(cn_arr.begin(), cn_arr.end(), [&](connected_node a, connected_node b) -> bool {
        return a.price < b.price;
    });
    vector<int> opt_prices;
    for (connected_node node : cn_arr) {
        int rootu = findRoot(node.u);
        int rootv = findRoot(node.v);
        if (rootu != rootv) {
            root[rootu] = rootv;
            opt_prices.push_back(node.price);
        }
    }
    vector<int> pref_prices(opt_prices.size()+1, 0);
    for (int i = 0; i < opt_prices.size(); i++) {
        pref_prices[i+1] = pref_prices[i] + opt_prices[i];
    }
    while (q--) {
        int x;
        cin >> x;
        int left = 0;
        int right = opt_prices.size();
        while (left < right) {
            int mid = (left+right)>>1;
            int costA = pref_prices[mid] + x * ((n-mid-1) * (n-mid-1+1) / 2);
            int costB = pref_prices[mid+1] + x * ((n-(mid+1)-1) * (n-(mid+1)-1+1) / 2);
            // we consider if costA stop at mid or costB stop at mid+1 is better
            if (costA-costB >= 0) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int k = n - left - 1;
        int cost = pref_prices[left] + x * (k * (k+1) / 2);
        cout << profit - cost << ' ';
    }
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}





