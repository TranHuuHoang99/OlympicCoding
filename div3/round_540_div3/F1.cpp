/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-06 19:42:43
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 3e5+10;
int n;
int A[N];
vector<int> adj[N];
int save[N][3];
int total_red, total_blue;
int ret = 0;
void dfs(int u, int parent) {
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        for (int i = 0; i <= 2; i++) {
            save[u][i] += save[v][i];
        }
    }
    save[u][A[u]]++;
}
void dfs_ret(int u, int parent) {
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs_ret(v, u);
        int red = save[v][1];
        int blue = save[v][2];
        if (red > 0 && blue > 0) continue;
        int rem_red = total_red - red;
        int rem_blue = total_blue - blue;
        if (rem_red > 0 && rem_blue > 0) continue;
        ret++;
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
    dfs(1, 1);
    total_red = save[1][1];
    total_blue = save[1][2];
    dfs_ret(1, 1);
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}






