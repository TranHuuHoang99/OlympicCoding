/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-10-27 20:43:47
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 3e3+10;
int n, m;
int sum[N];
int st[N], ed[N];
vector<int> ans;
void fill(void) {
    vector<bool> used(n, false);
    for (int i = 1; i <= n; i++) {
        if (ans[i] != -1) {
            used[ans[i]] = true;
        }
    }
    int add = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i] == -1) {
            while (used[add]) add++;
            ans[i] = add;
            used[add] = true;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
}
void solve() {
    cin >> n >> m;
    memset(sum, 0, sizeof(sum));
    memset(st, 0, sizeof(st));
    memset(ed, 0, sizeof(ed));
    vector<pair<int,int>> A(m);
    for (int i = 0; i < m; i++) {
        cin >> A[i].first >> A[i].second;
        st[A[i].first] = 1;
        ed[A[i].second] = 1;
        for (int j = A[i].first; j <= A[i].second; j++) {
            sum[j] += 1;
        }
    }
    ans.assign(n+1, -1);
    for (int i = 1; i <= n; i++) {
        if (sum[i] == m) {
            ans[i] = 0;
            fill();
            return;
        }
    }
    for (int i = 1; i < n; i++) {
        if (ed[i] == 0) {
            ans[i] = 0;
            ans[i+1] = 1;
            fill();
            return;
        }
        if (st[i+1] == 0) {
            ans[i+1] = 0;
            ans[i] = 1;
            fill();
            return;
        }
    }
    ans[1] = 0;
    ans[2] = 2;
    ans[3] = 1;
    fill();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
