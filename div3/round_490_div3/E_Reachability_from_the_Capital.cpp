/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-27 21:19:02
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3+10;
int n, m, capital;
vector<int> adj[N];
bool isConnected[N];
bool visited[N];
int numb[N];
void dfs_capital(int u) {
    isConnected[u] = true;
    numb[u]++;
    for (int v : adj[u]) {
        if (isConnected[v]) continue;
        dfs_capital(v);
        numb[u] += numb[v];
    }
}
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (visited[v]) continue;
        dfs(v);
    }
}
bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first > b.first;
}
void solve(void) {
    cin >> n >> m >> capital;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs_capital(capital);
    int max_val = numb[capital];
    int master = capital;
    for (int i = 1; i <= n; i++) {
        if (isConnected[i]) {
            if (max_val < numb[i]) {
                master = i;
                max_val = numb[i];
            }
        }
    }
    vector<pair<int,int>> save;
    for (int i = 1; i <= n; i++) {
        if (!isConnected[i]) {
            memset(visited, 0, sizeof(visited));
            dfs(i);
            int cnt = 0;
            for (int u = 1; u <= n; u++) {
                if (visited[u] && !isConnected[u]) {
                    cnt++;
                }
            }
            save.push_back({cnt, i});
        }
    }
    sort(save.begin(), save.end(), cmp);
    memset(visited, 0, sizeof(visited));
    int ret = 0;
    for (pair<int,int> s : save) {
        int comp = s.second;
        if (visited[comp]) continue;
        ret++;
        adj[master].push_back(comp);
        dfs(capital);
    }
    cout << ret << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





