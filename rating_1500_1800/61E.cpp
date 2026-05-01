/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-04-30 20:21:33
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6+10;
int n;
int A[N];
map<int,int> save;
int it_left[4*N], it_right[4*N];
int stronger[N], weaker[N];
void update(int idx, int left, int right, int pos, int* it) {
    if (left > pos || right < pos) return;
    if (left == right) {
        if (left == pos) it[idx] += 1;
        return;
    }
    int mid = (left+right)/2;
    update(idx*2, left, mid, pos, it);
    update(idx*2+1, mid+1, right, pos, it);
    it[idx] = it[idx*2] + it[idx*2+1];
}
int get_val(int idx, int left, int right, int u, int v, int* it) {
    if (u > right || v < left) return 0;
    if (u <= left && right <= v) return it[idx];
    int mid = (left+right)/2;
    int left_val = get_val(idx*2, left, mid, u, v, it);
    int right_val = get_val(idx*2+1, mid+1, right, u, v, it);
    return left_val + right_val;
}
void solve(void) {
    cin >> n;
    vector<int> arr;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        arr.push_back(A[i]);
    }
    int cnt = 1;
    sort(arr.begin(), arr.end());
    for (int a : arr) {
        auto it = save.find(a);
        if (it == save.end()) {
            save[a] = cnt;
            cnt++;
        }
    }
    // calculate the number of previous strongers
    for (int i = 1; i <= n; i++) {
        int strg = save[A[i]];
        int val = get_val(1, 1, n, strg+1, n, it_left);
        stronger[i] = val;
        update(1, 1, n, strg, it_left);
    }
    // calculate the number of behind weakers
    for (int i = n; i >= 1; i--) {
        int strg = save[A[i]];
        int val = get_val(1, 1, n, 1, strg-1, it_right);
        weaker[i] = val;
        update(1, 1, n, strg, it_right);
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        ret += stronger[i] * weaker[i];
    }
    cout << ret << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





