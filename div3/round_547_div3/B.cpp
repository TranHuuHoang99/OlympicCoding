/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-23 11:18:51
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n;
int A[N];
void solve(void) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    int cnt = 0;
    int ret = 0;
    int idx = 0;
    int i = 0;
    while (i < 2 * n) {
        if (A[idx%n] == 1) {
            cnt++;
            ret = max(ret, cnt);
        } else {
            cnt = 0;
        }
        idx++;
        i++;
    }
    cout << ret << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





