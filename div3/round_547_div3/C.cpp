/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-23 11:25:29
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n;
int Q[N];
int pref[N];
int ret[N];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        cin >> Q[i];
        pref[i] = pref[i-1] + Q[i];
    }
    /*
        we have P2 = P1 + Q1
        => P3 = P2 + Q2
        <=> P3 = P1 + Q1 + Q2
        => general equation
        => Pi = P1 + pref[i-1]
        we need to find P1
        let say we have min(P) is 1
        => min(P) = P1 + min(pref)
        because P is an array of permutation
        => min(P) = 1
        => P1 = 1 - min(pref)
    */
    int min_val = LLONG_MAX;
    for (int i = 1; i <= n; i++) min_val = min(min_val, pref[i]);
    int P1 = 1 - min_val;
    if (P1 < 0 || P1 > n) {
        cout << -1 << '\n';
        return;
    }
    ret[1] = P1;
    set<int> check;
    check.insert(ret[1]);
    for (int i = 1; i <= n-1; i++) {
        ret[i+1] = ret[i] + Q[i];
        check.insert(ret[i+1]);
        if (ret[i+1] < 0 || ret[i+1] > n) {
            cout << -1 << '\n';
            return;
        }
    }
    if (check.size() != n) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) cout << ret[i] << ' ';
    cout << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





