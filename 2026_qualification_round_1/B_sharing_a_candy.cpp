/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-05-30 09:30:23
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n;
int A[N];
int prefix[N];
int L[N], R[N];
int it_max[4*N], it_min[4*N];
void build_max(int idx, int left, int right) {
    if (left == right) {
        it_max[idx] = prefix[left];
        return;
    }
    int mid = (left+right)/2;
    build_max(idx*2, left, mid);
    build_max(idx*2+1, mid+1, right);
    it_max[idx] = max(it_max[idx*2], it_max[idx*2+1]);
}
int query_max(int idx, int left, int right, int u, int v) {
    if (u > right || v < left) return -1e17;
    if (u <= left && right <= v) return it_max[idx];
    int mid = (left+right)/2;
    int left_val = query_max(idx*2, left, mid, u, v);
    int right_val = query_max(idx*2+1, mid+1, right, u, v);
    return max(left_val, right_val);
}
void build_min(int idx, int left, int right) {
    if (left == right) {
        it_min[idx] = prefix[left];
        return;
    }
    int mid = (left+right)/2;
    build_min(idx*2, left, mid);
    build_min(idx*2+1, mid+1, right);
    it_min[idx] = min(it_min[idx*2], it_min[idx*2+1]);
}
int query_min(int idx, int left, int right, int u, int v) {
    if (u > right || v < left) return 1e17;
    if (u <= left && right <= v) return it_min[idx];
    int mid = (left+right)/2;
    int left_val = query_min(idx*2, left, mid, u, v);
    int right_val = query_min(idx*2+1, mid+1, right, u, v);
    return min(left_val, right_val);
}
void solve(void) {
    cin >> n;
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + A[i];
    build_max(1, 0, n);
    build_min(1, 0, n);
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && A[st.top()] <= A[i]) st.pop();
        L[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && A[st.top()] < A[i]) st.pop();
        R[i] = st.empty() ? n+1 : st.top();
        st.push(i);
    }
    int ret = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        int lu = L[i], lv = i-1;
        int ru = i, rv = R[i] - 1;
        int max_val = query_max(1, 0, n, ru, rv);
        int min_val = query_min(1, 0, n, lu, lv);
        ret = max(ret, max_val - min_val - A[i]);
    }
    cout << ret << endl;
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





