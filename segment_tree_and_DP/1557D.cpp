/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-05-23 11:58:55
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 6e5+10;
int n, m;
vector<pair<int,int>> A[N];
vector<int> store;
pair<int,int> it[4*N], lazy[4*N];
int track[N];
bool selected[N];
void push(int idx) {
    it[idx*2] = max(it[idx*2], lazy[idx]);
    it[idx*2+1] = max(it[idx*2+1], lazy[idx]);
    lazy[idx*2] = max(lazy[idx*2], lazy[idx]);
    lazy[idx*2+1] = max(lazy[idx*2+1], lazy[idx]);
    lazy[idx] = {0,0};
}
void update(int idx, int left, int right, int u, int v, pair<int,int> val) {
    if (u > right || v < left) return;
    if (u <= left && right <= v) {
        it[idx] = max(it[idx], val);
        lazy[idx] = max(lazy[idx], val);
        return;
    }
    int mid = (left+right)/2;
    push(idx);
    update(idx*2, left, mid, u, v, val);
    update(idx*2+1, mid+1, right, u, v, val);
    it[idx] = max(it[idx*2], it[idx*2+1]);
}
pair<int,int> query(int idx, int left, int right, int u, int v) {
    if (u > right || v < left) return {0,0};
    if (u <= left && right <= v) return it[idx];
    int mid = (left+right)/2;
    push(idx);
    pair<int,int> left_val = query(idx*2, left, mid, u, v);
    pair<int,int> right_val = query(idx*2+1, mid+1, right, u, v);
    return max(left_val, right_val);
}
void solve(void) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int id, left, right;
        cin >> id >> left >> right;
        A[id].push_back({left, right});
        store.push_back(left);
        store.push_back(right);
    }
    sort(store.begin(), store.end());
    store.erase(unique(store.begin(), store.end()), store.end());
    int len = store.size();
    fill(track, track+n+5, 0);
    for (int i = 1; i <= n; i++) {
        for (pair<int,int>& iter : A[i]) {
            iter.first = lower_bound(store.begin(), store.end(), iter.first) - store.begin() + 1;
            iter.second = lower_bound(store.begin(), store.end(), iter.second) - store.begin() + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        pair<int,int> max_val = {0,0};
        for (pair<int,int> iter : A[i]) {
            max_val = max(max_val, query(1, 1, len, iter.first, iter.second));
        }
        track[i] = max_val.second;
        max_val.first += 1;
        max_val.second = i;
        for (pair<int,int> iter : A[i]) {
            update(1, 1, len, iter.first, iter.second, max_val);
        }
    }
    pair<int,int> ret = it[1];
    int cur = ret.second;
    while (cur != 0) {
        selected[cur] = true;
        cur = track[cur];
    }
    cout << n - ret.first << endl;
    for (int i = 1; i <= n; i++) {
        if (!selected[i]) cout << i << ' ';
    }
    cout << endl;
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





