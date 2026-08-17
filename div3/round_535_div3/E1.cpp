/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-24 22:22:37
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 1e5+10;
int n, m;
int A[N];
vector<pair<int,pair<int,int>>> save;
void solve(void) {
    cin >> n >> m;
    int f_min_val = LLONG_MAX;
    int f_max_val = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        f_min_val = min(f_min_val, A[i]);
        f_max_val = max(f_max_val, A[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        save.push_back({i, {u, v}});
    }
    int ret = f_max_val - f_min_val;
    vector<int> ret_arr;
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (u == v) continue;
            vector<int> temp;
            for (auto s : save) {
                auto [x, y] = s.second;
                if ((x <= u && u <= y) && (v < x || v > y)) {
                    temp.push_back(s.first);
                }
            }
            int min_val = A[u] + (-1 * (temp.size()));
            int max_val = A[v];
            if (max_val - min_val > ret) {
                ret = max_val - min_val;
                ret_arr = temp;
            }
        }
    }
    cout << ret << '\n';
    cout << ret_arr.size() << '\n';
    for (int r : ret_arr) cout << r << ' ';
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}




