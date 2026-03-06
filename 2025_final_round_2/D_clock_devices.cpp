/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-03-02 21:42:45
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10;
int n, c;
int D[N], W[N];
vector<int> adj[N];
bool visited[N];
int F[N][13];
int max_val[N];
void dfs(int u, int father) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (v == father || visited[v]) continue;
        dfs(v, u);
        for (int i = 1; i <= 12; i++) {
            F[u][i] += max(F[v][i], max_val[v] - c);
        }
    }
    F[u][D[u]] += W[u];
    for (int i = 1; i <= 12; i++) max_val[u] = max(max_val[u], F[u][i]);
}
void solve(void) {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> D[i];
    for (int i = 1; i <= n; i++) cin >> W[i];
    for (int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        dfs(i,i);
        ret += max_val[i];
    }
    cout << ret << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





