/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-08 13:41:47
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n, q;
int arr[N];
int it[4*N];
int lazy[4*N];
void push_down(int idx) {
    if (lazy[idx] == 0) return;
    it[idx*2] = max(it[idx*2], lazy[idx]);
    it[idx*2+1] = max(it[idx*2+1], lazy[idx]);
    lazy[idx*2] = max(lazy[idx*2], lazy[idx]);
    lazy[idx*2+1] = max(lazy[idx*2+1], lazy[idx]);
    lazy[idx] = 0;
}
void build(int idx, int left, int right) {
    if (left == right) {
        it[idx] = arr[left];
        return;
    }
    int mid = (left+right)>>1;
    build(idx*2, left, mid);
    build(idx*2+1, mid+1, right);
}
void update_all(int idx, int left, int right, int u, int v, int val) {
    if (u > right || v < left) return;
    if (u <= left && right <= v) {
        lazy[idx] = max(lazy[idx], val);
        it[idx] = max(it[idx], val);
        return;
    }
    int mid = (left+right)>>1;
    push_down(idx);
    update_all(idx*2, left, mid, u, v, val);
    update_all(idx*2+1, mid+1, right, u, v, val);
}
void update_point(int idx, int left, int right, int u, int val) {
    if (u < left || u > right) return;
    if (left == right) {
        it[idx] = val;
        return;
    }
    int mid = (left+right)>>1;
    push_down(idx);
    update_point(idx*2, left, mid, u, val);
    update_point(idx*2+1, mid+1, right, u, val);
}
int get_val_point(int idx, int left, int right, int u) {
    if (u < left || u > right) return 0;
    if (left == right) return it[idx];
    int mid = (left+right)>>1;
    push_down(idx);
    int left_val = get_val_point(idx*2, left, mid, u);
    int right_val = get_val_point(idx*2+1, mid+1, right, u);
    return left_val + right_val;
}
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, val;
            cin >> u >> val;
            update_point(1, 1, n, u, val);
        } else {
            int val;
            cin >> val;
            update_all(1, 1, n, 1, n, val);
        }
    }
    for (int u = 1; u <= n; u++) {
        int ret = get_val_point(1, 1, n, u);
        cout << ret << ' ';
    }
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





