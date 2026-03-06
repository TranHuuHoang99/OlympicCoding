/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-03-09 21:00:26
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10;
int n, k;
double A[N];
bool valid(double x) {
    vector<double> prefix(n+1, 0.0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + (A[i] * A[i] - x * A[i]);
    }
    double min_val = 0.0f;
    for (int i = k; i <= n; i++) {
        min_val = min(min_val, prefix[i-k]);
        if (prefix[i] - min_val >= 0) return true;
    }
    return false;
}
void solve(void) {
    cin >> n >> k;
    double max_val = 0.0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        max_val = max(max_val, A[i]);
    }
    double left = 1.0;
    double right = max_val;
    double ret = 0.0;
    for (int i = 1; i <= 80; i++) {
        double mid = (left+right)/2.0;
        if (valid(mid)) {
            ret = max(ret, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << fixed << setprecision(6) << ret << '\n';
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





