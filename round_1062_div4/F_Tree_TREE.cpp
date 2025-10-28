/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-10-29 19:53:13
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5+10;
int n, k;
vector<int> adj[N];
int sz[N];
int F_in[N], F_out[N];
void dfs_size(int u, int father) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == father) continue;
        dfs_size(v, u);
        sz[u] += sz[v];
    }
}
void dfs_out(int u, int father) {
    for (int v : adj[u]) {
        if (v == father) continue;
        dfs_out(v, u);
        F_out[u] += F_out[v];
    }
    if (sz[u] >= k) F_out[u] += 1;
}
void dfs_in(int u, int father) {
    for (int v : adj[u]) {
        if (v == father) continue;
        int add = 0;
        if (n - sz[v] + 1 >= k && F_out[v] == 0) add = 1;
        int add_out = 0;
        if (n - sz[v] >= k) {
            add_out = F_out[u] - F_out[v];
        }
        F_in[v] += F_in[u] + add + add_out;
        dfs_in(v, u);
    }
}
void solve() {
    cin >> n >> k;
    memset(sz, 0, sizeof(sz));
    memset(F_in, 0, sizeof(F_in));
    memset(F_out, 0, sizeof(F_out));
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_size(1, 0);
    dfs_out(1, 0);
    dfs_in(1, 0);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += F_out[i] + F_in[i];
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}