/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-19 18:14:21
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n, m, k;
int A[N];
void solve(void) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> A[i];
    int idx = n;
    int ret = 0;
    int cur = 0;
    int box = 1;
    while (idx >= 1 && box <= m) {
        if (cur + A[idx] < k) {
            cur += A[idx];
        } else if (cur + A[idx] == k) {
            cur = 0;
            box++;
        } else {
            if (box+1 > m) break;
            cur = A[idx];
            box++;
        }
        ret++;
        idx--;
    }
    cout << ret << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





