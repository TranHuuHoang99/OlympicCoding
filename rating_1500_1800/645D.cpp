/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-10 00:06:35
**************************************************************************
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define pi acos(-1.0)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int N = 1e5+10;
int n, m;
pair<int,int> arr[N];
bool is_valid(int m_first_matches) {
    queue<int> q;
    vector<int> in_degree(n+10, 0);
    vector<int> adj[n+1];
    for (int i = 1; i <= m_first_matches; i++) {
        auto [u, v] = arr[i];
        in_degree[v] += 1;
        adj[u].push_back(v);
    }
    for (int u = 1; u <= n; u++) {
        if (in_degree[u] == 0) q.push(u);
    }
    if (q.size() > 1) return false;
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        cnt += 1;
        q.pop();
        for (int v : adj[u]) {
            in_degree[v] -= 1;
            if (in_degree[v] == 0) q.push(v);
        }
        if (q.size() > 1) return false;
    }
    return cnt == n;
}
void solve(void) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        arr[i] = {u, v};
    }
    int left = 1;
    int right = m;
    int ret = -1;
    while (left <= right) {
        int mid = (left+right)>>1;
        if (is_valid(mid)) {
            ret = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (is_valid(m) && ret != -1) {
        cout << ret << '\n';
    } else {
        cout << -1 << '\n';
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





