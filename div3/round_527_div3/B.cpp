/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-29 23:33:51
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

int A[110];
int n;
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    sort(A+1, A+1+n);
    int ret = 0;
    for (int i = 2; i <= n; i+=2) {
        ret += A[i] - A[i-1];
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





