/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-05-23 12:38:46
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 1e5+10;
int n, d;
int H[N];
pair<int,int> it[4*N];
vector<int> store;
int track[N];
bool selected[N];
void update(int idx, int left, int right, int pos, pair<int,int> val) {
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
pair<int,int> query(int idx, int left, int right, int u, int v) {
    if (u > right || v < left) return {0,0};
    if (u <= left && right <= v) return it[idx];
    int mid = (left+right)/2;
    pair<int,int> left_val = query(idx*2, left, mid, u, v);
    pair<int,int> right_val = query(idx*2+1, mid+1, right, u, v);
    return max(left_val, right_val);
}
void solve(void) {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> H[i];
        store.push_back(H[i]);
    }
    sort(store.begin(), store.end());
    store.erase(unique(store.begin(), store.end()), store.end());
    int len = store.size();
    for (int i = 0; i <= 4*n+5; i++) it[i] = {0,0};
    fill(track, track+n+5, 0);
    fill(selected, selected+n+5, false);
    for (int i = 1; i <= n; i++) {
        pair<int,int> max_val = {0,0};
        int upper = upper_bound(store.begin(), store.end(), H[i] - d) - store.begin();
        if (upper > 0) {
            max_val = max(max_val, query(1, 1, len, 1, upper));
        }
        int lower = lower_bound(store.begin(), store.end(), H[i] + d) - store.begin() + 1;
        if (lower <= len) {
            max_val = max(max_val, query(1, 1, len, lower, len));
        }
        track[i] = max_val.second;
        max_val.first += 1;
        max_val.second = i;
        int index = lower_bound(store.begin(), store.end(), H[i]) - store.begin() + 1;
        update(1, 1, len, index, max_val);
    }
    pair<int,int> ret = it[1];
    int cur = ret.second;
    while (cur != 0) {
        selected[cur] = true;
        cur = track[cur];
    }
    cout << ret.first << endl;
    for (int i = 1; i <= n; i++) {
        if (selected[i]) cout << i << ' ';
    }
    cout << endl;
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





