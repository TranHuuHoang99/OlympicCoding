/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-10-22 11:21:25
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(void) {
    int n, k;
    cin >> n >> k;
    vector<int> A(n+1, 0);
    vector<int> odd_pos;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (A[i] % 2 == 1) odd_pos.push_back(i);
    }
    if (odd_pos.size() < k || ((odd_pos.size() - (k-1)) % 2 == 0)) {
        cout << "no\n";
        return;
    }
    cout << "yes\n";
    for (int i = 0; i < k-1; i++) cout << odd_pos[i] << ' ';
    cout << n << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}






