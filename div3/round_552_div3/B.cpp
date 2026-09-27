/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-27 21:15:45
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int n;
int A[110];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int val = 0; val <= 100; val++) {
        bool valid = true;
        for (int i = 2; i <= n; i++) {
            if (A[i] != A[1] && A[i] - val != A[1] && A[i] + val != A[1]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << val << '\n';
            return;
        }
        valid = true;
        for (int i = 2; i <= n; i++) {
            if (A[i] != A[1]+val && A[i]+val != A[1]+val && A[i]-val != A[1]+val) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << val << '\n';
            return;
        }
        valid = true;
        for (int i = 2; i <= n; i++) {
            if (A[i] != A[1]-val && A[i]+val != A[1]-val && A[i]-val != A[1]-val) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << val << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





