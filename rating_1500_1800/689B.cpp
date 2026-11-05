/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-11-05 23:35:30
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 2e5+10;
int n;
int A[N];
int F[N];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        F[i] = 1e18;
    }
    F[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur + 1 <= n && F[cur+1] > F[cur] + 1) {
            F[cur+1] = F[cur] + 1;
            q.push(cur+1);
        }
        if (cur - 1 >= 1 && F[cur-1] > F[cur] + 1) {
            F[cur-1] = F[cur] + 1;
            q.push(cur-1);
        }
        if (F[A[cur]] > F[cur] + 1) {
            F[A[cur]] = F[cur] + 1;
            q.push(A[cur]);
        }
    }
    for (int i = 1; i <= n; i++) cout << F[i] << ' ';
    cout << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





