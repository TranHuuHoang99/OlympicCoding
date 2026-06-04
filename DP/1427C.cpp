/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-06-02 09:01:21
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
    int t, x, y;
};
const int N = 1e5+10;
const int M = 1e6+10;
int r, n;
Node A[N];
int F[N];
int max_F[N];
int cal_dist(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}
void solve(void) {
    cin >> r >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i].t >> A[i].x >> A[i].y;
    }
    A[0] = {0,1,1};
    for (int i = 0; i <= n; i++) F[i] = max_F[i] = LLONG_MIN;
    F[0] = max_F[0] = 0;
    int ret = 0;
    int limit = 2 * r;
    for (int i = 1; i <= n; i++) {
        for (int j = i-1; j >= max(0ll, i-limit); j--) {
            if (F[j] == LLONG_MIN) continue;
            int cost = cal_dist(A[i].x, A[i].y, A[j].x, A[j].y);
            int diff = A[i].t - A[j].t;
            if (cost <= diff) {
                F[i] = max(F[i], F[j] + 1);
            }
        }
        if (i - limit - 1 >= 0) {
            int val = max_F[i-limit-1];
            if (val != LLONG_MIN) F[i] = max(F[i], val + 1);
        }
        max_F[i] = max(max_F[i-1], F[i]);
        ret = max(ret, F[i]);
    }
    cout << ret << endl;
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
