/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-02-27 22:14:23
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;
const int N = 3e4+200;
const int M = 110;
int G, D;
int F[N];
void solve(void) {
    cin >> G >> D;
    for (int i = 0; i <= G; i++) F[i] = 0;
    F[0] = 1;
    for (int i = 0; i <= G; i++) {
        for (int j = 1; j <= D; j++) {
            F[i+j] = (F[i+j] % MOD + F[i] % MOD) % MOD;
        }
    }
    cout << F[G] << endl;
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





