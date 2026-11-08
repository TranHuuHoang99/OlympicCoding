/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-08 18:45:43
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 1e5+10;
int n, k, m;
pair<int,int> friend_ships[N];
set<int> dislikes[N];
bool excluded_group[N];
int root[N];
int findRoot(int u) {
    if (u == root[u]) return u;
    return root[u] = findRoot(root[u]);
}
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) root[i] = i;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> friend_ships[i].first >> friend_ships[i].second;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        dislikes[u].insert(v);
        dislikes[v].insert(u);
    }
    auto is_not_dislike = [&](int u, int v) -> bool {
        auto it = dislikes[u].find(v);
        return it == dislikes[u].end();
    };
    for (int i = 1; i <= k; i++) {
        auto [u, v] = friend_ships[i];
        int rootu = findRoot(u);
        int rootv = findRoot(v);
        if (rootu != rootv) {
            root[rootu] = rootv;
        }
    }
    for (int u = 1; u <= n; u++) {
        if (excluded_group[root[u]]) continue;
        int rootu = findRoot(u);
        for (int v : dislikes[u]) {
            int rootv = findRoot(v);
            if (rootu == rootv && !is_not_dislike(u, v)) {
                excluded_group[rootv] = true;
                break;
            }
        }
    }
    map<int,int> save_max;
    for (int i = 1; i <= n; i++) {
        if (!excluded_group[root[i]]) {
            save_max[findRoot(i)] += 1;
        }
    }
    int ret = 0;
    for (pair<int,int> p : save_max) ret = max(ret, p.second);
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





