/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-09-27 20:52:21
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

vector<int> A;
void solve(void) {
    A.resize(4);
    for (int i = 0; i < 4; i++) cin >> A[i];
    sort(A.begin(), A.end());
    int max_val = A.back();
    int c = max_val - A[0];
    int a = A[1] - c;
    int b = A[2] - c;
    cout << a << ' ' << b << ' ' << c << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





