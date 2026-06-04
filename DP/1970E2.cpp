/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-05-28 15:17:31
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

struct Node {
    int s_trail, l_trail;
};
const int MOD = 1e9+7;
int m, n;
Node A[110];
void solve(void) {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> A[i].s_trail;
    for (int i = 1; i <= m; i++) cin >> A[i].l_trail;
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





