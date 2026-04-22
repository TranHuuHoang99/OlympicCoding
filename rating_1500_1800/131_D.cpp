/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-04-22 09:32:11
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e3+10;
int n;
vector<int> adj[N];
int dist[N];
bool visited[N];
int numb[N], low[N];
int timeDfs = 0;
void dfs(int u, int parent) {
    timeDfs++;
    numb[u] = low[u] = timeDfs;
    for (int v : adj[u]) {
        if (v == parent) continue;
        if (numb[v] == 0) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            if (numb[v] < low[u]) {
                dist[v] = 0;
            }
            low[u] = min(low[u], numb[v]);
        }
    }
}
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dist[i] = N;
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        if (low[i] != numb[i]) {
            dist[i] = 0;
            memset(visited, 0, sizeof(visited));
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (visited[v]) continue;
                    dist[v] = min(dist[v], dist[u] + 1);
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    for (int u = 1; u <= n; u++) cout << dist[u] << ' ';
    cout << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





