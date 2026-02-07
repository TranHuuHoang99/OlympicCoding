/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-29 17:24:39
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 110;
int n;
int A[N];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        A[val]++;
    }
    int max_val = 0;
    for (int i = 0; i <= 100; i++) max_val = max(max_val, A[i]);
    cout << max_val << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





