/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-21 15:03:39
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
multiset<int> A;
void solve(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        A.insert(val%k);
    }
    int ret = 0;
    for (int i = 1; i <= k/2; i++) {
        int left_val = A.count(i);
        int right_val = A.count(k-i);
        if (left_val > 0 && right_val > 0) {
            if (i == k-i) {
                ret += left_val / 2;
            } else {
                ret += min(left_val, right_val);
            }
        }
    }
    ret += A.count(0) / 2;
    cout << ret * 2 << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





