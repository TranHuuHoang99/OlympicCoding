/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-06-30 10:06:42
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n;
vector<int> adj[N];
int dist[N];
int parent[N];
void dfs(int u, int _parent, int _dist) {
    parent[u] = _parent;
    dist[u] = _dist;
    for (int v : adj[u]) {
        if (v == _parent) continue;
        dfs(v, u, _dist + 1);
    }
}
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    set<pair<int,int>> save;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > 2) {
            save.insert({-dist[i], i});
        }
    }
    int ret = 0;
    while (!save.empty()) {
        int u = save.begin()->second;
        ret += 1;
        int v = parent[u];
        auto it = save.find({-dist[v], v});
        if (it != save.end()) save.erase(it);
        for (int child : adj[v]) {
            auto _it = save.find({-dist[child], child});
            if (_it != save.end()) save.erase(_it);
        }
    }
    cout << ret << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





