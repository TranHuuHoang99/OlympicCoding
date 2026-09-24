/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-25 11:03:08
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, m;
vector<int> adj[N];
vector<pair<pair<int,int>, int>> store;
int color[N];
bool dfs(int u, int c) {
    color[u] = c;
    for (auto v : adj[u]) {
        if (color[v] == -1) {
            if (!dfs(v, 1 - c)) return false;
        } else if (color[v] == color[u]) {
            return false;
        }
    }
    return true;
}
void solve(void) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        store.push_back({{u, v}, i});
    }
    for (int i = 1; i <= n; i++) color[i] = -1;
    if (!dfs(1, 0)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    string ret("0", m);
    for (auto it : store) {
        auto [u, v] = it.first;
        int idx = it.second;
        int status = color[u];
        ret[idx-1] = status == 0 ? '0' : '1';
    }
    cout << ret << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





