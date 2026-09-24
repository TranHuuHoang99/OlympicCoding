/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-24 14:07:45
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, k;
vector<pair<int,int>> adj[N];
int ret[N];
int len;
void dfs(int u, int parent, int c_color) {
    int c = 1;
    for (auto [v, idx] : adj[u]) {
        if (v == parent) continue;
        if (c == c_color) c++;
        if (c > len) {
            c = 1;
        }
        ret[idx] = c;
        dfs(v, u, c);
        c++;
    }
}
void solve(void) {
    cin >> n >> k;
    for (int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    vector<int> vertices(n);
    iota(vertices.begin(), vertices.end(), 1);
    sort(vertices.begin(), vertices.end(), [&] (int a, int b) -> bool {
        return adj[a].size() > adj[b].size();
    });
    len = adj[vertices[k]].size();
    dfs(1, 1, 0);
    cout << len << '\n';
    for (int i = 1; i <= n-1; i++) cout << ret[i] << ' ';
    cout << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





