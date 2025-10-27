/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2025-10-28 11:09:33
**************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void solve() {
    cin >> n;
    if (n <= 2) {
        cout << -1 << endl;
        return;
    }
    if (n == 3) {
        cout << 3 << ' ' << 2 << endl;
        cout << 3 << ' ' << 1 << endl;
        return;
    }
    if (n == 4) {
        cout << 4 << ' ' << 2 << endl;
        cout << 2 << ' ' << 3 << endl;
        cout << 2 << ' ' << 1 << endl;
        return;
    }
    if (n == 5) {
        cout << 5 << ' ' << 1 << endl;
        cout << 1 << ' ' << 2 << endl;
        cout << 2 << ' ' << 3 << endl;
        cout << 3 << ' ' << 4 << endl;
        return;
    }
    vector<vector<int>> adj(n+1);
    adj[1].push_back(n);
    adj[3].push_back(4);
    adj[2].push_back(1);
    adj[2].push_back(3);
    for (int i = 5; i <= n-1; i++) adj[2].push_back(i);
    for (int u = 1; u <= n; u++) {
        for (int v  : adj[u]) {
            cout << u << ' ' << v << endl;
        }
    }
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
