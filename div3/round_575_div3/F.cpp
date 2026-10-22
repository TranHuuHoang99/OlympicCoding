/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-23 13:52:32
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node {
    int u, w;
    bool operator < (const node& other) const {
        return this->w > other.w;
    }
};
struct node_path {
    int u, v, w;
};
const int N = 2e5+10;
vector<pair<int,int>> adj[N];
int dist[N];
int n, m, k;
void solve(void) {
    cin >> n >> m >> k;
    vector<node_path> save;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        save.push_back({u, v, w});
    }
    sort(save.begin(), save.end(), [&](node_path a, node_path b) -> bool {
        return a.w < b.w;
    });
    if (m > k) {
        save.resize(k);
    }
    int cnt = 1;
    map<int,int> vertex_compress;
    for (node_path s : save) {
        if (vertex_compress.find(s.u) == vertex_compress.end()) {
            vertex_compress[s.u] = cnt++;
        }
        if (vertex_compress.find(s.v) == vertex_compress.end()) {
            vertex_compress[s.v] = cnt++;
        }
        int u = vertex_compress[s.u];
        int v = vertex_compress[s.v];
        adj[u].push_back({v, s.w});
        adj[v].push_back({u, s.w});
    }
    int len = vertex_compress.size();
    multiset<int> ret;
    for (int root = 1; root <= len; root++) {
        for (int i = 1; i <= len; i++) dist[i] = LLONG_MAX;
        priority_queue<node> pq;
        pq.push({root, 0});
        dist[root] = 0;
        while (!pq.empty()) {
            auto [u, w] = pq.top();
            pq.pop();
            if (dist[u] < w) continue;
            for (auto [v, n_w] : adj[u]) {
                if (dist[v] > w + n_w) {
                    dist[v] = w + n_w;
                    pq.push({v, dist[v]});
                }
            }
        }
        for (int i = root+1; i <= len; i++) {
            if (dist[i] != LLONG_MAX) ret.insert(dist[i]);
        }
    }
    if (ret.size() < k) {
        cout << -1 << '\n';
    } else {
        cout << *next(ret.begin(), k-1) << '\n';
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}






