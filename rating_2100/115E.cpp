/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2026-05-07 19:45:42 
************************************************************************** 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Race {
    int u, v, w;
};
const int N = 2e5+10;
int n, m;
Race race[N];
int cost[N];
int it[4*N], lazy[4*N];
int F[N];
void push(int idx) {
    if (lazy[idx]) {
        it[idx*2] += lazy[idx];
        it[idx*2+1] += lazy[idx];
        lazy[idx*2] += lazy[idx];
        lazy[idx*2+1] += lazy[idx];
        lazy[idx] = 0;
    }
}
void update(int idx, int left, int right, int u, int v, int val) {
    if (u > right || v < left) return;
    if (u <= left && right <= v) {
        it[idx] += val;
        lazy[idx] += val;
        return;
    }
    int mid = (left+right)/2;
    push(idx);
    update(idx*2, left, mid, u, v, val);
    update(idx*2+1, mid+1, right, u, v, val);
    it[idx] = max(it[idx*2], it[idx*2+1]);
}
void set_val(int idx, int left, int right, int pos, int val) {
    if (left > pos || right < pos) return;
    if (left == right && left == pos) {
        it[idx] = val;
        lazy[idx] = 0;
        return;
    }
    int mid = (left+right)/2;
    push(idx);
    set_val(idx*2, left, mid, pos, val);
    set_val(idx*2+1, mid+1, right, pos, val);
    it[idx] = max(it[idx*2], it[idx*2+1]);
}
int query(int idx, int left, int right, int u, int v) {
    if (u > right || v < left) return INT32_MIN;
    if (u <= left && right <= v) return it[idx];
    int mid = (left+right)/2;
    push(idx);
    int left_val = query(idx*2, left, mid, u, v);
    int right_val = query(idx*2+1, mid+1, right, u, v);
    return max(left_val, right_val);
}
void solve(void) {
    cin >> n >> m;
    fill(it, it+4*n, INT32_MIN);
    fill(lazy, lazy+4*n, 0);
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        cost[i] = cost[i-1] + val;
    }
    for (int i = 1; i <= m; i++) {
        cin >> race[i].u >> race[i].v >> race[i].w;
    }
    sort(race+1, race+1+m, [=](Race a, Race b) -> bool {
        return a.v < b.v;
    });
    set_val(1, 0, n, 0, 0);
    int index = 1;
    for (int i = 1; i <= n; i++) {
        while (index <= m && race[index].v == i) {
            // all path from 0 -> u-1 will be added with race profit
            update(1, 0, n, 0, race[index].u-1, race[index].w);
            index++;
        }
        int max_val = query(1, 0, n, 0, i-1) - cost[i];
        F[i] = max(F[i-1], max_val);
        set_val(1, 0, n, i, F[i] + cost[i]);
    }
    cout << F[n] << endl;
}
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
















