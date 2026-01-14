/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-09 08:32:29
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
    int s_day, e_day, numb;
    int index;
};
int n, m;
Node A[110];
int ans[110];
void solve(void) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> A[i].s_day >> A[i].e_day >> A[i].numb;
        A[i].index = i;
    }
    sort(A+1, A+1+m, [&] (const Node& a, const Node& b) -> bool {
        return a.e_day < b.e_day;
    });
    for (int i = 1; i <= m; i++) {
        ans[A[i].e_day] = m+1;
    }
    for (int i = 1; i <= m; i++) {
        int need = A[i].numb;
        for (int day = A[i].s_day; day < A[i].e_day && need > 0; day++) {
            if (ans[day] == 0) {
                ans[day] = A[i].index;
                need--;
            }
        }
        if (need > 0) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}