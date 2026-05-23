/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-05-23 11:35:26
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 1e5+10;
int n;
int vol[N];
vector<int> store;
int it[8*N];
void update(int idx, int left, int right, int pos, int val) {
    if (pos > right || pos < left) return;
    if (left == right) {
        it[idx] = max(it[idx], val);
        return;
    }
    int mid = (left+right)/2;
    update(idx*2, left, mid, pos, val);
    update(idx*2+1, mid+1, right, pos, val);
    it[idx] = max(it[idx*2], it[idx*2+1]);
}
int query(int idx, int left, int right, int u, int v) {
    if (u > right || v < left) return 0;
    if (u <= left && right <= v) return it[idx];
    int mid = (left+right)/2;
    int left_val = query(idx*2, left, mid, u, v);
    int right_val = query(idx*2+1, mid+1, right, u, v);
    return max(left_val, right_val);
}
int get(int volume) {
    return lower_bound(store.begin(), store.end(), volume) - store.begin() + 1;
}
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int r, h;
        cin >> r >> h;
        vol[i] = r * r * h;
        store.push_back(vol[i]);
    }
    sort(store.begin(), store.end());
    store.erase(unique(store.begin(), store.end()), store.end());
    int len = store.size();
    for (int i = 1; i <= n; i++) {
        int index = get(vol[i]);
        int max_val = query(1, 0, len, 0, index-1);
        update(1, 0, len, index, max_val + vol[i]);
    }
    double ret = (double)it[1] * pi;
    cout << fixed << setprecision(9) << ret << endl;
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





