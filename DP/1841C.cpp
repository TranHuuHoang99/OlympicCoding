/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-06-17 13:28:19
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

map<char,int> save = {
    {'A', 1},  
    {'B', 10},  
    {'C', 100},  
    {'D', 1000},  
    {'E', 10000}  
};
const int N = 2e5+10;
string str;
int it[4*N];
void build(int idx, int left, int right) {
    if (left == right) {
        it[idx] = save[str[left]];
        return;
    }
    int mid = (left+right)/2;
    build(idx*2, left, mid);
    build(idx*2+1, mid+1, right);
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
void solve(void) {
    str.clear();
    cin >> str;
    int n = str.size();
    str = " " + str;
    build(1, 1, n);
    vector<int> store(n+10, 0);
    vector<int> prefix_pos(n+10, 0);
    vector<int> prefix(n+10, 0), suffix(n+10, 0);
    for (int i = 1; i <= n; i++) {
        int cur = save[str[i]];
        int val = 0;
        if (i+1 <= n) {
            val = query(1, 1, n, i+1, n);
        }
        if (cur >= val) {
            store[i] = cur;
            if (cur != 10000) prefix_pos[i] = cur;
        } else {
            store[i] = -cur;
        }
    }
    for (int i = 1; i <= n; i++) {
        prefix_pos[i] += prefix_pos[i-1];
        prefix[i] = prefix[i-1] + ((store[i] == 10000 || store[i] < 0) ? store[i] : 0);
    }
    for (int i = n; i >= 1; i--) {
        suffix[i] = suffix[i+1] + store[i];
    }
    int ret = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        int pre_origin = prefix[i-1];
        int prefix_left = prefix_pos[i-1];
        int suffix_right = suffix[i+1];
        int change = 10000;
        ret = max(ret, change + suffix_right - prefix_left + pre_origin);
    }
    cout << ret << endl;
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}





