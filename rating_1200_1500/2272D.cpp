/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-25 12:43:34
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(void) {
    int k;
    cin >> k;
    vector<pair<int,int>> ret;
    vector<pair<int,int>> ret_one;
    for (int i = 1; i <= k; i++) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        for (int j = 1; j <= n-1; j++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (n == 1) {
            ret_one.push_back({i, 1});
            continue;
        }
        vector<vector<int>> f_in(n+1, vector<int>(2, 0));
        auto dfs_in = [&](auto& self, int u, int parent) -> void {
            f_in[u][0] = 0;
            f_in[u][1] = 1;
            for (int v : adj[u]) {
                if (v == parent) continue;
                self(self, v, u);
                f_in[u][0] += max(f_in[v][0], f_in[v][1]);
                f_in[u][1] += f_in[v][0];
            }
        };
        dfs_in(dfs_in, 1, 1);
        vector<vector<int>> f_out(n+1, vector<int>(2, 0));
        auto dfs_out = [&](auto& self, int u, int parent) -> void {
            int best_child = 0; // for un-chosen parent
            int unchosen_child = 0; // for chosen parent
            for (int v : adj[u]) {
                if (v == parent) continue;
                best_child += max(f_in[v][0], f_in[v][1]);
                unchosen_child += f_in[v][0];
            }
            for (int v : adj[u]) {
                if (v == parent) continue;
                int other_best_child = best_child - max(f_in[v][0], f_in[v][1]);
                int other_unchosen_child = unchosen_child - f_in[v][0];
                f_out[v][0] = max(f_out[u][0] + other_best_child, 1 + f_out[u][1] + other_unchosen_child);
                f_out[v][1] = f_out[u][0] + other_best_child;
                self(self, v, u);
            }
        };
        dfs_out(dfs_out, 1, 1);
        int max_val = -1;
        int root = -1;
        for (int u = 1; u <= n; u++) {
            int total = f_in[u][0] + max(f_out[u][0], f_out[u][1]);
            if (total > max_val) {
                max_val = total;
                root = u;
            }
        }
        ret.push_back({i, root});
    }
    if (ret.empty()) {
        for (int i = 1; i < ret_one.size(); i++) {
            cout << ret_one[0].first << ' ' << ret_one[0].second << ' ' << ret_one[i].first << ' ' << ret_one[i].second << '\n';
        }
        return;
    }
    for (int i = 0; i < ret.size()-1; i++) {
        cout << ret[i].first << ' ' << ret[i].second << ' ' << ret[i+1].first << ' ' << ret[i+1].second << '\n';
    }
    for (int i = 0; i < ret_one.size(); i++) {
        cout << ret[0].first << ' ' << ret[0].second << ' ' << ret_one[i].first << ' ' << ret_one[i].second << '\n';
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}






