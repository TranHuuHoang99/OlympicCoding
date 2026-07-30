/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-06 22:31:21
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n;
int A[N];
vector<int> adj[N];
// distance from current node to the root node (which is 1)
int dist[N];
// sum of current node calculated follow by distance to root (1)
int sum[N];
// sum cost all children of current node not multiply with dist to root
int cost[N];
// current maximal value whose not managed by current node
int F_out[N];
// current maximal value whose managed by current node
int F_in[N];
void pre_dfs(int u, int parent) {
    cost[u] = A[u];
    for (int v : adj[u]) {
        if (v == parent) continue;
        dist[v] = dist[u] + 1;
        pre_dfs(v, u);
        cost[u] += cost[v];
        sum[u] += sum[v];
    }
    sum[u] += dist[u] * A[u];
}
void dfs(int u, int parent) {
    F_out[u] = F_out[parent] + cost[1] - cost[parent]
               + sum[parent] - sum[u] - (cost[parent] - cost[u]) * (dist[parent] - 1); 
    F_in[u] = sum[u] - dist[u] * (cost[u] - A[u]) - dist[u] * A[u];
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
    }
}
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pre_dfs(1, 1);
    dfs(1, 1);
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        ret = max(ret, F_out[i] + F_in[i]);
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





