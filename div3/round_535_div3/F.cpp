/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-03 21:20:51
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n, m;
int root[N];
map<int,vector<pair<int,int>>> save;
int findRoot(int u) {
    if (u == root[u]) return u;
    root[u] = findRoot(root[u]);
    return root[u];
}
void solve(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        save[w].push_back({u, v});
    }
    int ret = 0;
    for (auto it : save) {
        int potential_edges = 0;
        for (pair<int,int> p : it.second) {
            if (findRoot(p.first) != findRoot(p.second)) {
                potential_edges++;
            }
        }
        int merged_edges = 0;
        for (pair<int,int> p : it.second) {
            auto [u, v] = p;
            int rootu = findRoot(u);
            int rootv = findRoot(v);
            if (rootu != rootv) {
                root[rootu] = rootv;
                merged_edges++;
            }
        }
        ret += (potential_edges - merged_edges);
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





