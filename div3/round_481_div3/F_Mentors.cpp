/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-05 14:53:35
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, k;
int A[N];
int prefix[N];
map<int,int> save;
vector<int> adj[N];
void solve(void) {
    cin >> n >> k;
    int len = 1;
    set<int> temp;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        temp.insert(A[i]);
    }
    for (int t : temp) {
        save[t] = len;
        len++;
    }
    for (int i = 1; i <= n; i++) {
        A[i] = save[A[i]];
        prefix[A[i]]++;
    }
    for (int i = 1; i <= len; i++) prefix[i] += prefix[i-1];
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(A[v]);
        adj[v].push_back(A[u]);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(adj[i].begin(), adj[i].end(), A[i]);
        int cnt = it - adj[i].begin();
        cout << prefix[A[i]-1] - cnt << ' ';
    }
    cout << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}