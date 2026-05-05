/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-05-05 12:43:23
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e4 + 5e3 + 10;
const int M = 55;
int n, k;
int A[N];
map<int,int> save;
int pos[N];
int F[M][N];
int it[4*N], lazy[4*N];
void build(int idx, int left, int right, int box) {
    lazy[idx] = 0;
    if (left == right) {
        it[idx] = F[box][left];
        return;
    }
    int mid = (left+right)/2;
    build(idx*2, left, mid, box);
    build(idx*2+1, mid+1, right, box);
    it[idx] = max(it[idx*2], it[idx*2+1]);
}
void lazy_push(int idx) {
    if (lazy[idx] != 0) {
        it[idx*2] += lazy[idx];
        it[idx*2+1] += lazy[idx];
        lazy[idx*2] += lazy[idx];
        lazy[idx*2+1] += lazy[idx];
        lazy[idx] = 0ll;
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
    lazy_push(idx);
    update(idx*2, left, mid, u, v, val);
    update(idx*2+1, mid+1, right, u, v, val);
    it[idx] = max(it[idx*2], it[idx*2+1]);
}
int get_val(int idx, int left, int right, int u, int v) {
    if (u > right || v < left) return 0;
    if (u <= left && right <= v) {
        return it[idx];
    }
    int mid = (left+right)/2;
    lazy_push(idx);
    int left_val = get_val(idx*2, left, mid, u, v);
    int right_val = get_val(idx*2+1, mid+1, right, u, v);
    return max(left_val, right_val);
}
void solve(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        pos[i] = save[A[i]];
        save[A[i]] = i;
    }
    set<int> temp;
    for (int i = 1; i <= n; i++) {
        temp.insert(A[i]);
        F[1][i] = temp.size();
    }
    for (int i = 2; i <= k; i++) {
        build(1, 0, n-1, i-1);
        for (int j = 1; j <= n; j++) {
            if (pos[j] < j) {
                update(1, 0, n-1, pos[j], j-1, 1);
            }
            F[i][j] = get_val(1, 0, n-1, 0, j-1);
        }
    }
    cout << F[k][n] << endl;
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





