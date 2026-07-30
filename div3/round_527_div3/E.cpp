/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-02 11:25:48
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 1e3+10;
int n, m;
vector<int> adj[N];
int dist[N];
int root[N];
map<int,vector<pair<int,int>>> save;
int findRoot(int u) {
    if (u == root[u]) return u;
    root[u] = findRoot(root[u]);
    return root[u];
}
int dfs(int u, int parent, int n_dist) {
    int rootu = findRoot(u);
    int rootv = findRoot(parent);
    if (rootu != rootv) {
        root[rootu] = rootv;
    }
    int max_val = 0;
    for (int v : adj[u]) {
        if (v == parent) continue;
        max_val = max(max_val, dfs(v, u, n_dist+1));
    }
    return max(max_val, n_dist);
}
void solve(void) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 1; i <= n; i++) {
        dist[i] = dfs(i, i, 0);
    }
    int ret_val = -1;
    for (int u = 1; u <= n; u++) {
        int rootu = findRoot(u);
        save[rootu].push_back({dist[u], u});
        ret_val = max(ret_val, dist[u]);
    }
    for (auto& s : save) sort(s.second.begin(), s.second.end());
    vector<pair<int,int>> temp;
    for (auto s : save) {
        pair<int,int> min_p = *s.second.begin();
        temp.push_back(min_p);
    }
    sort(temp.begin(), temp.end());
    pair<int,int> master = temp.back();
    vector<pair<int,int>> ret_arr;
    for (int i = 0; i < temp.size()-1; i++) {
        ret_arr.push_back({temp[i].second, master.second});
        ret_val = max(ret_val, temp[i].first + master.first + 1);
    }
    if (temp.size() >= 3) {
        pair<int,int> g_max = temp[temp.size()-2];
        pair<int,int> g_m_max = temp[temp.size()-3];
        ret_val = max(ret_val, g_max.first + g_m_max.first + 2);
    }
    cout << ret_val << '\n';
    if (!ret_arr.empty()) {
        for (pair<int,int> r : ret_arr) cout << r.first << ' ' << r.second << '\n';
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





