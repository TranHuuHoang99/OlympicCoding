/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-28 11:02:54
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n, b, a;
int A[N];
void solve(void) {
    cin >> n >> b >> a;
    for (int i = 1; i <= n; i++) cin >> A[i];
    int max_capacity = a;
    int idx = -1;
    for (int i = 1; i <= n; i++) {
        if (a == 0 && b == 0) break;
        if (a == 0) {
            b--;
            if (A[i] == 1)
                a = min(max_capacity, a + 1);
        } else if (b == 0) {
            a--;
        } else {
            if (A[i] == 1 && a < max_capacity) {
                b--;
                a++;
            } else {
                a--;
            }
        }
        idx = i;
    }
    cout << idx << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





