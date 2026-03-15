/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-03-18 21:57:18
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, q;
vector<int> adj[N];
int timeDfs = 0;
int save[N];
int rev_save[N];
int cnt[N];
void dfs(int u, int parent) {
    timeDfs++;
    save[timeDfs] = u;
    rev_save[u] = timeDfs;
    cnt[u]++;
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
}
void solve(void) {
    cin >> n >> q;
    for (int v = 2; v <= n; v++) {
        int u;
        cin >> u;
        adj[u].push_back(v);
    }
    dfs(1, -1);
    for (int i = 1; i <= q; i++) {
        int u, k;
        cin >> u >> k;
        if (k > cnt[u]) {
            cout << -1 << endl;
            continue;
        }
        int time_val = rev_save[u];
        cout << save[time_val+k-1] << endl;
    }
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





