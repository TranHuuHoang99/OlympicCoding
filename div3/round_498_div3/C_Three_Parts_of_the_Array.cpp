/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-03-15 20:18:58
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n;
int A[N];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    int ret = 0;
    int left = 0, right = n+1;
    int sum1 = 0, sum2 = 0;
    while (left < right) {
        if (sum1 < sum2) {
            sum1 += A[++left];
        } else if (sum2 < sum1) {
            sum2 += A[--right];
        } else {
            ret = left;
            sum1 += A[++left];
            sum2 += A[--right];
        }
    }
    int sum = 0;
    for (int i = 1; i <= ret; i++) sum += A[i];
    cout << sum << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





