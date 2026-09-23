/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-22 21:57:40
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n, m, d;
vector<pair<int,int>> A;
multiset<int> save;
map<int,int> man_ver;
int root[N];
int findRoot(int u) {
    if (u == root[u]) return u;
    return root[u] = findRoot(root[u]);
}
void solve(void) {
    cin >> n >> m >> d;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        A.push_back({u, v});
        if (u == 1) save.insert(v);
        if (v == 1) save.insert(u);
    }
    for (int i = 1; i <= n; i++) root[i] = i;
    for (pair<int,int> p : A) {
        if (p.first == 1 || p.second == 1) continue;
        int rootu = findRoot(p.first);
        int rootv = findRoot(p.second);
        if (rootu != rootv) {
            root[rootu] = rootv;
        }
    }
    for (int s : save) {
        int roots = findRoot(s);
        man_ver[roots] = s;
    }
    int c = man_ver.size();
    if (c > d || save.size() < d) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= n; i++) root[i] = i;
    vector<pair<int,int>> ret;
    for (pair<int,int> mand : man_ver) {
        int rootu = findRoot(1);
        int rootv = findRoot(mand.second);
        if (rootu != rootv) {
            root[rootu] = rootv;
            ret.push_back({1, mand.second});
            auto it = save.find(mand.second);
            save.erase(it);
        }
    }
    int cnt = c;
    for (auto it = save.begin(); it != save.end() && cnt < d; it++) {
        int rootu = findRoot(1);
        int rootv = findRoot(*it);
        if (rootu != rootv) {
            root[rootu] = rootv;
            ret.push_back({1, *it});
            cnt++;
        }
    }
    for (pair<int,int> p : A) {
        if (p.first == 1 || p.second == 1) continue;
        int rootu = findRoot(p.first);
        int rootv = findRoot(p.second);
        if (rootu != rootv) {
            ret.push_back({p.first, p.second});
            root[rootu] = rootv;
        }
    }
    if (ret.size() != n-1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (pair<int,int> r : ret) cout << r.first << ' ' << r.second << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





