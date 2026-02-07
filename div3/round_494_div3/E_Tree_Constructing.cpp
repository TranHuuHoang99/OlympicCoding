/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-31 12:50:36
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 4e5+10;
int n, d, k;
int dist[N];
vector<pair<int,int>> ret;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
void solve(void) {
    cin >> n >> d >> k;
    if (d >= n) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < d; i++) {
        dist[i]++;
        dist[i+1]++;
        if (dist[i] > k || dist[i+1] > k) {
            cout << "NO" << endl;
            return;
        }
        ret.push_back({i, i+1});
    }
    for (int i = 1; i < d; i++) {
        q.push({max(i, d-i), i});
    }
    for (int v = d+1; v < n; v++) {
        while (!q.empty() && dist[q.top().second] == k) {
            q.pop();
        }
        if (q.empty() || q.top().first == d) {
            cout << "NO" << endl;
            return;
        }
        int u = q.top().second;
        int cur_dist = q.top().first;
        dist[u]++;
        dist[v]++;
        ret.push_back({u, v});
        q.push({cur_dist+1, v});
    }
    cout << "YES" << endl;
    for (pair<int,int> r : ret) {
        cout << r.first+1 << ' ' << r.second+1 << endl;
    }
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





