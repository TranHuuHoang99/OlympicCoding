/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-17 22:10:32
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 1e3+10;
int n, r;
int A[N];
void solve(void) {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) cin >> A[i];
    int i = 1;
    int ret = 0;
    while (i <= n) {
        int left = max(1ll, i-r+1);
        int right = min(n, i+r-1);
        int pick = -1;
        for (int j = right; j >= left; j--) {
            if (A[j] == 1) {
                pick = j;
                break;
            }
        }
        if (pick == -1) {
            cout << -1 << '\n';
            return;
        }
        ret += 1;
        i = pick + r;
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





