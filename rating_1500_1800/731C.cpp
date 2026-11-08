/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-08 16:17:09
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n, m, k;
int colors[N];
bool used[N];
vector<int> adj[N];
set<pair<int,int>> check_exist;
map<int,int> numb_same_color[N];
int numb_child[N];
void dfs(int u, int parent, int root) {
    used[u] = true;
    numb_same_color[root][colors[u]] += 1;
    for (int v : adj[u]) {
        if (v == parent || used[v]) continue;
        dfs(v, u, root);
        numb_child[u] += numb_child[v];
    }
    numb_child[u] += 1;
}
void solve(void) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> colors[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        auto it = check_exist.find({u, v});
        if (it != check_exist.end()) continue;
        check_exist.insert({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ret = 0;
    for (int u = 1; u <= n; u++) {
        if (used[u]) continue;
        dfs(u, -1, u);
        int max_val = 0;
        for (pair<int,int> p : numb_same_color[u]) {
            max_val = max(max_val, p.second);
        }
        ret += (numb_child[u] - max_val);
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





