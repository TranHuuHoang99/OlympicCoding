/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-09 13:25:59
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 1e5+10;
int n;
int A[N];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    if (n <= 2) {
        cout << 0 << '\n';
        return;
    }
    sort(A+1, A+1+n);
    int ret = min(A[n] - A[2], A[n-1] - A[1]);
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





