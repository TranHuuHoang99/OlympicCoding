/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-09 19:45:18
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n;
vector<int> adj[N];
bool visited[N];
vector<int> store;
map<int,vector<int>> save;
void dfs(int u, int parent) {
    store.push_back(u);
    visited[u] = true;
    for (int v : adj[u]) {
        if (v == parent || visited[v]) continue;
        dfs(v, u);
    }
}
void solve(void) {
    cin >> n;
    pair<int,int> s = {0,0};
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        save[i].push_back(u);
        save[i].push_back(v);
        if (s.first == 0 && s.second == 0) {
            s = {u,v};
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(s.first, s.second);
    int check_point = store[0];
    vector<int> check_a = {store[1], store[2]};
    sort(check_a.begin(), check_a.end());
    sort(save[check_point].begin(), save[check_point].end());
    if (check_a == save[check_point]) {
        for (int s : store) cout << s << ' ';
        cout << '\n';
    } else {
        for (int i = n-1; i >= 0; i--) cout << store[i] << ' ';
        cout << '\n';
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





