/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-10 21:05:29
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n, m;
int A[N];
int root[N];
vector<pair<pair<int,int>, int>> save;
int findRoot(int u) {
    if (u == root[u]) return u;
    return root[u] = findRoot(root[u]);
}
void solve(void) {
    cin >> n >> m;
    pair<int,int> max_val = {1e13, -1};
    for (int i = 1; i <= n; i++) {
        root[i] = i;
        cin >> A[i];
        if (A[i] < max_val.first) {
            max_val = {A[i], i};
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        save.push_back({{u, v}, w});
    }
    int u = max_val.second;
    for (int v = 1; v <= n; v++) {
        if (v == max_val.second) continue;
        save.push_back({{u, v}, max_val.first + A[v]});
    }
    sort(save.begin(), save.end(), [&] (pair<pair<int,int>, int> a, pair<pair<int,int>, int> b) -> bool {
        return a.second < b.second;
    });
    int ret = 0;
    for (int i = 0; i < save.size(); i++) {
        auto [u, v] = save[i].first;
        int w = save[i].second;
        int rootu = findRoot(u);
        int rootv = findRoot(v);
        if (rootu != rootv) {
            ret += w;
            root[rootu] = rootv;
        }
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





