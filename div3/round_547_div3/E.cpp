/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-23 14:55:29
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int h, n;
int A[N];
int prefix[N];
void solve(void) {
    cin >> h >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        prefix[i] = prefix[i-1] + A[i];
    }
    // pre-checking
    for (int i = 1; i <= n; i++) {
        if (h + prefix[i] <= 0) {
            cout << i << '\n';
            return;
        }
    }
    int last_val = prefix[n];
    if (last_val >= 0) {
        cout << -1 << '\n';
        return;
    }
    int ret = -1;
    for (int i = 1; i <= n; i++) {
        int val = h + prefix[i];
        int round = (val + -prefix[n] - 1) / -prefix[n];
        int minute = round * n + i;
        if (ret == -1 || minute < ret) {
            ret = minute;
        }
    }
    cout << ret << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





