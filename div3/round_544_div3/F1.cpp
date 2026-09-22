/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-22 16:39:44
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, m;
int root[N];
map<int,vector<int>> save;
vector<pair<int,vector<int>>> arr;
bool cmp(pair<int,vector<int>> a, pair<int,vector<int>> b) {
    return a.second.size() > b.second.size();
}
int findRoot(int u) {
    if (u == root[u]) return u;
    root[u] = findRoot(root[u]);
    return root[u];
}
void solve(void) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        save[u].push_back(v);
        save[v].push_back(u);
    }
    for (pair<int,vector<int>> s : save) {
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 1; i <= n; i++) root[i] = i;
    for (pair<int,vector<int>> a : arr) {
        int u = a.first;
        for (int v : a.second) {
            int rootu = findRoot(u);
            int rootv = findRoot(v);
            if (rootu != rootv) {
                cout << u << ' ' << v << '\n';
                root[rootu] = rootv;
            }
        }
    }
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





