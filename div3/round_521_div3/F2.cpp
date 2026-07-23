/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-07-27 21:49:40
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 5010;
int n, k, x;
int A[N];
// F[i][j] is the maximum beauty of the pictures
// when we already had i number of pictures
// and the j'th picture is the choosen for the next
int F[2][N];
void solve(void) {
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 0; i <= n; i++) F[0][i] = LLONG_MIN;
    F[0][0] = 0;
    deque<int> dq;
    for (int i = 0; i < x; i++) {
        int cur = i & 1;
        int next = (i+1) & 1;
        dq.clear();
        for (int j = 1; j <= n; j++) F[next][j] = LLONG_MIN;
        for (int j = 1; j <= n; j++) {
            while (!dq.empty() && F[cur][dq.back()] < F[cur][j-1]) {
                dq.pop_back();
            }
            dq.push_back(j-1);
            while (!dq.empty() && dq.front() < j-k) {
                dq.pop_front();
            }
            if (!dq.empty() && F[cur][dq.front()] != LLONG_MIN) {
                F[next][j] = F[cur][dq.front()] + A[j];
            }
        }
    }
    int ret = LLONG_MIN;
    for (int i = n-k+1; i <= n; i++) {
        if (i >= 1) ret = max(ret, F[x&1][i]);
    }
    if (ret == LLONG_MIN) {
        cout << -1 << '\n';
    } else {
        cout << ret << '\n';
    }
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





