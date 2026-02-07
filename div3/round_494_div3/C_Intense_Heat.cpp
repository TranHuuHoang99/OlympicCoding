/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-01-31 07:29:49
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3+10;
double A[N];
double prefix[N];
int n, k;
void solve(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + A[i];
    double ret = 0.0f;
    for (int len = k; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            if (i+len-1 > n) break;
            double sum = prefix[i+len-1] - prefix[i-1];
            ret = max(ret, sum / (len / 1.0F));
        }
    }
    cout << fixed << setprecision(15) << ret << endl;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





