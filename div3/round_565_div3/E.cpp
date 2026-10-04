/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-05 15:58:18
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, m;
vector<int> adj[N];
int dist[N];
bool visited[N];
vector<int> odd_ret;
vector<int> even_ret;
void init(void) {
}
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (visited[v]) continue;
        dist[v] = dist[u] + 1;
        if (dist[v] % 2 == 0) {
            even_ret.push_back(v);
        } else {
            odd_ret.push_back(v);
        }
        dfs(v);
    }
}
void solve(void) {
    cin >> n >> m;
    odd_ret.clear();
    even_ret.clear();
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        visited[i] = false;
        dist[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    even_ret.push_back(1);
    dist[1] = 0;
    dfs(1);
    if (even_ret.size() <= odd_ret.size()) {
        cout << even_ret.size() << '\n';
        for (int e_r : even_ret) cout << e_r << ' ';
        cout << '\n';
    } else {
        cout << odd_ret.size() << '\n';
        for (int o_r : odd_ret) cout << o_r << ' ';
        cout << '\n';
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}






