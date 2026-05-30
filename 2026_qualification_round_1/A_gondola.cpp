/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-05-30 08:40:21
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 1e5+10;
int n, k;
int A[N];
int it[6*N];
int root[N];
bool visited[N];
vector<pair<int,pair<int,int>>> store;
void build(int idx, int left, int right) {
    if (left == right) {
        it[idx] = A[left];
        return;
    }
    int mid = (left+right)/2;
    build(idx*2, left, mid);
    build(idx*2+1, mid+1, right);
    it[idx] = max(it[idx*2], it[idx*2+1]);
}
int query(int idx, int left, int right, int u, int v) {
    if (u > right || v < left) return INT32_MIN;
    if (u <= left && right <= v) return it[idx];
    int mid = (left+right)/2;
    int left_val = query(idx*2, left, mid, u, v);
    int right_val = query(idx*2+1, mid+1, right, u, v);
    return max(left_val, right_val);
}
int findRoot(int u) {
    if (u == root[u]) return u;
    int rootu = findRoot(root[u]);
    root[u] = rootu;
    return rootu;
}
void solve(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        root[i] = i;
        visited[i] = false;
    }
    if (n < 2 * k) {
        cout << -1 << endl;
        return;
    }
    build(1, 1, n);
    for (int i = 1; i <= n-k; i++) {
        int val = query(1, 1, n, i, i+k);
        store.push_back({val, {i, i+k}});
    }
    for (int i = 1; i <= n-k-1; i++) {
        int val = query(1, 1, n, i, i+k+1);
        store.push_back({val, {i, i+k+1}});
    }
    sort(store.begin(), store.end(), [&] (pair<int,pair<int,int>> a, pair<int,pair<int,int>> b) -> bool {
        return a.first < b.first;
    });
    int ret = 0;
    for (pair<int,pair<int,int>> iter : store) {
        int u = iter.second.first;
        int v = iter.second.second;
        int rootu = findRoot(u);
        int rootv = findRoot(v);
        if (rootu == rootv) continue;
        ret += iter.first;
        visited[u] = true;
        visited[v] = true;
        root[rootu] = rootv;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << ret << endl;
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





