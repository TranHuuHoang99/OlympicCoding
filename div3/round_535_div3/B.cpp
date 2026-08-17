/*
**************************************************************************
    author     : hoangprodn
    email  	   : thhoang08091999@gmail.com
    local time : 2026-08-20 22:15:41
**************************************************************************
*/
#include <bits/stdc++.h>
#define int long long
#define pi acos(-1.0)
using namespace std;

const int N = 1e4+10;
int cnt[N];
int n;
int A[200];
void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }
    sort(A+1, A+1+n);
    int x = A[n];
    int y = -1;
    for (int i = 1; i <= x; i++) {
        if (x % i == 0) cnt[i]--;
    }
    for (int i = n-1; i >= 1; i--) {
        if (cnt[A[i]] > 0) {
            y = A[i];
            break;
        }
    }
    cout << x << ' ' << y << '\n';
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}





