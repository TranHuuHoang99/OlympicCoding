/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-02-17 22:24:17
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, m, k;
vector<int> adj[N];
int U[N], V[N];
int dist[N];
vector<int> inc[N];
int path[N];
void solve(void) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) dist[i] = INT32_MAX;
    for (int i = 1; i <= m; i++) {
        cin >> U[i] >> V[i];
        adj[U[i]].push_back(V[i]);
        adj[V[i]].push_back(U[i]);
    }
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INT32_MAX) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (dist[U[i]] + 1 == dist[V[i]]) {
            inc[V[i]].push_back(i);
        }
        if (dist[V[i]] + 1 == dist[U[i]]) {
            inc[U[i]].push_back(i);
        }
    }
    vector<string> ret;
    for (int i = 1; i <= k; i++) {
        string temp(m, '0');
        for (int u = 2; u <= n; u++) {
            if (!inc[u].empty()) {
                temp[inc[u][path[u]]-1] = '1';
            }
        }
        ret.push_back(temp);
        bool valid = false;
        for (int u = 2; u <= n; u++) {
            if (path[u]+1 < inc[u].size()) {
                path[u] += 1;
                valid = true;
                break;
            } else {
                path[u] = 0;
            }
        }
        if (!valid) break;
    }
    cout << ret.size() << endl;
    for (string str : ret) cout << str << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





