/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-30 10:29:32
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n;
int A[N];
int C[N];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    multiset<int> B;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        B.insert(val);
    }
    for (int i = 1; i <= n; i++) {
        int target = 0;
        if (A[i] == 0) {
            target = 0;
        } else {
            target = n - A[i];
        }
        auto it = B.lower_bound(target);
        int found = -1;
        if (it != B.end()) {
            found = *it;
            B.erase(it);
        } else {
            int left_most = *B.begin();
            int right_most = *prev(B.end());
            int left_rem = (A[i] + left_most) % n;
            int right_rem = (A[i] + right_most) % n;
            if (left_rem < right_rem) {
                found = left_most;
                B.erase(B.begin());
            } else {
                found = right_most;
                B.erase(prev(B.end()));
            }
        }
        C[i] = (A[i] + found) % n;
    }
    for (int i = 1; i <= n; i++) cout << C[i] << ' ';
    cout << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





