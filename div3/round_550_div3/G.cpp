/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-25 14:10:44
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
const int INF = 2e6;
int n;
int A[N];
int F_inc[N], F_dec[N];
int parent_status[N][2];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) {
        F_inc[i] = -INF;
        F_dec[i] = INF;
    }
    // the first element must fit in decrease sequence so F_inc[1] must be maximized
    F_inc[1] = INF;
    // the first element must fit in increase sequence so F_dec[1] must be minimized
    F_dec[1] = -INF; 
    for (int i = 1; i < n; i++) {
        if (F_inc[i] != -INF) {
            // currently A[i] is in increase sequence and we decide put A[i+1] in increase sequence
            // also, so the last element must be put in decrease sequence stop at F_inc[i]
            if (A[i+1] > A[i]) {
                if (F_inc[i] > F_inc[i+1]) {
                    F_inc[i+1] = F_inc[i];
                    parent_status[i+1][0] = 0;
                }
            }
            // we decide to put A[i+1] to decrease sequence so we compare with the best element we
            // have so far
            if (A[i+1] < F_inc[i]) {
                if (F_dec[i+1] > A[i]) {
                    F_dec[i+1] = A[i];
                    parent_status[i+1][1] = 0;
                }
            }
        }
        if (F_dec[i] != INF) {
            // we decide put A[i+1] into increase
            if (A[i+1] > F_dec[i]) {
                if (A[i] > F_inc[i+1]) {
                    F_inc[i+1] = A[i];
                    parent_status[i+1][0] = 1;
                }
            }
            // we decide put A[i+1] into decrease
            if (A[i+1] < A[i]) {
                if (F_dec[i+1] > F_dec[i]) {
                    F_dec[i+1] = F_dec[i];
                    parent_status[i+1][1] = 1;
                }
            }
        }
    }
    int cur_status = -1;
    if (F_inc[n] != -INF) {
        cur_status = 0;
    } else if (F_dec[n] != INF) {
        cur_status = 1;
    } else {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> ret(n+1);
    for (int i = n; i >= 1; i--) {
        ret[i] = cur_status;
        cur_status = parent_status[i][cur_status];
    }
    for (int i = 1; i <= n; i++) cout << ret[i] << ' ';
    cout << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





