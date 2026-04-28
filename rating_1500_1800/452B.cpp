/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-04-24 13:06:54
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(void) {
    int n, m;
    cin >> n >> m;
    if (n == 0) {
        cout << 0 << ' ' << 1 << endl;
        cout << 0 << ' ' << m << endl;
        cout << 0 << ' ' << 0 << endl;
        cout << 0 << ' ' << m-1 << endl;
        return;
    }
    if (m == 0) {
        cout << 1 << ' ' << 0 << endl;
        cout << n << ' ' << 0 << endl;
        cout << 0 << ' ' << 0 << endl;
        cout << n-1 << ' ' << 0 << endl;
        return;
    }
    double hypotnuse = sqrt(pow((double)n, 2) + pow((double)m, 2));
    double hypotnuse_m = sqrt(pow((double)n-1, 2) + pow((double)m, 2));
    double hypotnuse_n = sqrt(pow((double)n, 2) + pow((double)m-1, 2));
    if (n >= m) {
        double sum1 = hypotnuse * 2.0f + (double)n;
        double sum2 = hypotnuse + 2.0f * hypotnuse_n;
        if (sum1 >= sum2) {
            cout << 0 << ' ' << 0 << endl;
            cout << n << ' ' << m << endl;
            cout << 0 << ' ' << m << endl;
            cout << n << ' ' << 0 << endl;
        } else {
            cout << n << ' ' << m-1 << endl;
            cout << 0 << ' ' << 0 << endl;
            cout << n << ' ' << m << endl;
            cout << 0 << ' ' << 1 << endl;
        }
    } else {
        double sum1 = hypotnuse * 2.0f + (double)m;
        double sum2 = hypotnuse + 2.0f * hypotnuse_m;
        if (sum1 >= sum2) {
            cout << 0 << ' ' << 0 << endl;
            cout << n << ' ' << m << endl;
            cout << n << ' ' << 0 << endl;
            cout << 0 << ' ' << m << endl;
        } else {
            cout << 1 << ' ' << 0 << endl;
            cout << n << ' ' << m << endl;
            cout << 0 << ' ' << 0 << endl;
            cout << n-1 << ' ' << m << endl;
        }
    }
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





