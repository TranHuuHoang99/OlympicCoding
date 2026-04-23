/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-04-23 20:20:26
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, t;
int prefix[N];
int it[8*N];
vector<int> save;
void update(int idx, int left, int right, int pos) {
    if (left > pos || right < pos) return;
    if (left == right) {
        if (left == pos) it[idx]++;
        return;
    }
    int mid = (left+right)/2;
    update(idx*2, left, mid, pos);
    update(idx*2+1, mid+1, right, pos);
    it[idx] = it[idx*2] + it[idx*2+1];
}
int get_val(int idx, int left, int right, int u, int v) {
    if (u > right || v < left) return 0;
    if (u <= left && right <= v) return it[idx];
    int mid = (left+right)/2;
    int left_val = get_val(idx*2, left, mid, u, v);
    int right_val = get_val(idx*2+1, mid+1, right, u, v);
    return left_val + right_val;
}
void solve(void) {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        prefix[i] = prefix[i-1] + val;
        save.push_back(prefix[i]);
        save.push_back(prefix[i]-t);
    }
    save.push_back(0);
    sort(save.begin(), save.end());
    save.resize(unique(save.begin(), save.end()) - save.begin());
    auto get_idx = [=] (const int& val) -> int {
        return lower_bound(save.begin(), save.end(), val) - save.begin() + 1;
    };
    int sz = save.size();
    update(1, 1, sz, get_idx(0));
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        int val = prefix[i] - t;
        int idx = get_idx(val);
        ret += get_val(1, 1, sz, idx+1, sz);
        idx = get_idx(prefix[i]);
        update(1, 1, sz, idx);
    }
    cout << ret << endl;
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





