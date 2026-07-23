/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-23 22:29:15
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int A[120];
void solve(void) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    int ret = 0;
    for (int i = 2; i <= n-1; i++) {
        if (A[i-1] == 1 && A[i] == 0 && A[i+1] == 1) {
            ret += 1;
            A[i+1] = 0;
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





